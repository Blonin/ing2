Ech1 = read.csv("EspVieACPData.txt",sep = "")
table(Ech1$CONT)
pie(table(Ech1$CONT))
table(Ech1$EV)
pie(table(Ech1$EV))

anova(lm(Ech1$EV~Ech1$CONT,data = Ech1))

boxplot(Ech1$EV)

boxplot(Ech1$EV[Ech1$CONT=="ASIE"],Ech1$EV[Ech1$CONT=="AFRIQUE"],Ech1$EV[Ech1$CONT=="EUROPE"],Ech1$EV[Ech1$CONT=="OCEANIE"],Ech1$EV[Ech1$CONT=="AMERSUD"])

echantillon=data[sample(nrow(data),50,)]

boxplo(EV~CONT,data=echantillon)
unique(data$cont)
points(1,mean(oceanie$ev))

# pvaleur très petit du coup on rejet h0 donc dépendance
# refaire les tests sans l'afrique puisque trop loin

# pour anova deux point wilconson si 2 ech

#verification des valeurs extrème 
# il existe des valeur extrème
# anova ne fonctionne pas enfin les résultats de l'anova ne donnerons pas de résultats satisfaisant
# test non parametrique
# 