Ech1 = read.csv("Ech1.txt",sep = "")
Ech2 = read.csv("Ech2.txt",sep = "")
Ech3 = read.csv("Ech3.txt",sep = "")
Ech4 = read.csv("Ech4.txt",sep = "")
Ech5 = read.csv("Ech5.txt",sep = "")

moy1 = mean(Ech1$Echantillon)
ecartype1 = sd(Ech1$Echantillon)
moy2 = mean(Ech2$Echantillon)
ecartype2 = sd(Ech2$Echantillon)
moy3 = mean(Ech3$Echantillon)
ecartype3 = sd(Ech3$Echantillon)
moy4 = mean(Ech4$Echantillon)
ecartype4 = sd(Ech4$Echantillon)
moy5 = mean(Ech5$Echantillon)
ecartype5 = sd(Ech5$Echantillon)

datas = c(Ech1,Ech2,Ech3,Ech4,Ech5)

hist(sapply(Ech5, as.numeric),nclass=10)


#3 1,2,3, H0 u=0.5 H1 u >0.5
# test de student entre l'echantillon 1 et 2
res = t.test(Ech1,Ech2)
proba = res$p.value
res$parameter 
res$conf.int 
res$statistic

shapiro.test(Ech1$Echantillon)
shapiro.test(Ech2$Echantillon)  
var12 = var.test(Ech1$Echantillon,Ech2$Echantillon) 

resultat = t.test(Ech1$Echantillon,Ech2$Echantillon,var.equal=F) 
resultat$p.value 
resultat$parameter 
resultat$conf.int
resultat$statistic

res1 = t.test(Ech1,mu=0.5)
res2 = t.test(Ech2,mu=0.5)
#t val a 2. val espérance plus grande que 0.5
res3 = t.test(Ech3,mu=0.5)
# moy est encore + grande que l ech2 peut problable que ce soit 0.5
# donc on reject surement H0
proba = res1$p.value
res1$parameter 
res1$conf.int 
res1$statistic

proba = res2$p.value
res2$parameter 
res2$conf.int 
res2$statistic


proba = res3$p.value
res3$parameter 
res3$conf.int 
res3$statistic


res4 = t.test(Ech4,mu=0.5,alternative = "greater")

# 1 e 2 moy sup a 0.5 donc on accepte h1
