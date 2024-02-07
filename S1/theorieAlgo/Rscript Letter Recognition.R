Mydata=read.table("letter-recognition.data",header=F,sep=",")
Mydata$V1=as.factor(Mydata$V1)

# V?rification de la r?partition des classes
table(Mydata$V1)
pie(table(Mydata$V1))

# Cr?ation bases apprentissage (2/3), validation (1/6) et test (1/6)
n=nrow(Mydata)
# Base apprentissage
ntrain=floor(2*n/3)
index=sample(1:n,ntrain,replace=F)
train=Mydata[index,]
reste=Mydata[-index,]
# Bases validation et test
nval=floor(n/6)
indexval=sample(1:nrow(reste),nval,replace=F)
validation=reste[indexval,]
test=reste[-indexval,]

# Centrer et r?duire
# Calul moyenne et ?cart-type uniquement sur base d'apprentissage
moy=apply(train[,-1],2,mean) # moyenne colonne par colonne
ecartype=apply(train[,-1],2,sd) # ?cart-type colonne par colonne
train[,-1]=scale(train[,-1],center=moy,scale=ecartype) 
# Transformation sur validation et test
validation[,-1]=scale(validation[,-1],center=moy,scale=ecartype)
apply(validation[,-1],2,mean)
apply(validation[,-1],2,sd)
test[,-1]=scale(test[,-1],center=moy,scale=ecartype)
apply(test[,-1],2,mean)
apply(test[,-1],2,sd)


# Arbre de décision
library(rpart)
library(rpart.plot)
ArbreR=rpart(V1~.,train)
prp(ArbreR)
ArbreMoi=rpart(V1~.,train,control = rpart.control(minsplit=10,minbucket=10,cp=0,maxdepth = 30))
#prp(ArbreMoi)
#plotcp(ArbreMoi)
# Erreur train
prev.t=predict(ArbreMoi,train,type="class") # pr?vision de la base d'apprentissage
MatConf.t=table(train$V1,prev.t) # Matrice de confusion
tbc.t=sum(diag(MatConf.t))/sum(MatConf.t) # Taux de bien class?s

# Erreur Validation
prev.v=predict(ArbreMoi,validation,type="class") # pr?vision de la base de validation
MatConf.v=table(validation$V1,prev.v) # Matrice de confusion
tbc.v=sum(diag(MatConf.v))/sum(MatConf.v) # Taux de bien class?s

# For?ts aléatoires
library(randomForest)

Foret=randomForest(V1~.,data=train,ntree=100,mtry=4,nodesize=1)
plot(Foret$err.rate[,1], type="l") 
show(Foret)
Foret$oob.times

# Erreur train
prev.t=predict(Foret,train,type="class") # pr?vision de la base d'apprentissage
MatConf.t=table(train$V1,prev.t) # Matrice de confusion
tbc.t=sum(diag(MatConf.t))/sum(MatConf.t) # Taux de bien class?s

# Erreur Validation
prev.v=predict(Foret,validation,type="class") # pr?vision de la base de validation
MatConf.v=table(validation$V1,prev.v) # Matrice de confusion
tbc.v=sum(diag(MatConf.v))/sum(MatConf.v) # Taux de bien class?s


# Comparaison des méthodes
# Erreur Test Arbre
prev.test=predict(ArbreMoi,test,type="class") # pr?vision de la base de test
MatConf.test=table(test$V1,prev.test) # Matrice de confusion
tbc.test.arbre=sum(diag(MatConf.test))/sum(MatConf.test) # Taux de bien class?s
# Erreur Test Foret
prev.test=predict(Foret,test,type="class") # pr?vision de la base de test
MatConf.test=table(test$V1,prev.test) # Matrice de confusion
tbc.test.foret=sum(diag(MatConf.test))/sum(MatConf.test) # Taux de bien class?s

#######
# Naives Bayes
library(e1071)


table(test$V1)
modele=naiveBayes(test$V1,test)
print(modele)
prev=predict(modele,Mydata)
MatConf=table(Mydata$Recommendation,prev)
print(MatConf)






