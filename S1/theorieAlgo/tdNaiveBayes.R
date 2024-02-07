library(e1071)

Mydata=read.table("lenses.txt",header=T)
table(Mydata$Recommendation)
modele=naiveBayes(V1.,Mydata)
print(modele)
prev=predict(modele,Mydata)
MatConf=table(Mydata$Recommendation,prev)
print(MatConf)