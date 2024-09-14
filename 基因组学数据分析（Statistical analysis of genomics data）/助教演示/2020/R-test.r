##��Ҫ
##R�������ݣ���������
##R�򵥵���ͼ����


##���ù���·��
setwd("E:/20200929_Rstudio_test")

##�����ı��ļ���.txt�ļ���
age <- read.delim("age.txt", header=FALSE)

##���붺�ŷָ��ļ���.csv�ļ���
weight <- read.csv("weight.csv", header=FALSE)

##����excel�ļ�������ת��.csv��ʽ��
#����1
install.packages("RODBC") #ͨ��RODBC��������excel
library(RODBC) #����RODBC��
data <- odbcConnectExcel("file.xls") #odbcConnectExcel is only usable with 32-bit Windows
#����2
install.packages("xlsx") #ͨ��xlsx��������excel
library(xlsx) #����xlsx��
data <- read.xlsx("file.xlsx")


##���ٶ�ȡ��������
install.packages("data.table") #��װdata.table���������ϴ����ݼ�������
library(data.table)
data<- fread("Big_data.txt")

tmp_data <- age$V1 + weight$V1


##��������
write.table(tmp_data,file="tmp_data.txt",col.names=F) #����Ϊtxt�ļ�
write.csv(tmp_data,file="tmp_data.csv") #����Ϊcsv�ļ�
save(tmp_data,file="tmp_data.Rdata") #����R�ļ�������load("tmp_data.Rdata")��ע�������


##���õ�һЩ����
#mode(age) #��ʾ���������
#names(age) #��ʾ�����еı�ǩ
#dim(age) #��ʾ�����ά��
#mean(weight) #��ֵ
#sd(weight)   #����
#cor(age, weight) #�����

rm(list = ls()) #��ջ��������б���
# Ctrl + L ��տ���̨


##����������Ƿ���ȱʧֵ
test_data <- c(1, 3, NA, 2, NA, 9, 3, 9, 12, 3)
is.na(test_data) #���� TRUE or FALSE 
which(is.na(test_data)) #����ȱʧֵλ��
sum(is.na(test_data))  #�������ݼ���ȱʧֵ����
data <- na.omit(test_data) #ȥ��ȱʧֵ

rm(list = ls()) #��ջ��������б���


##ɢ��ͼ
age <- c(1, 3, 5, 2, 11, 9, 3, 9, 12, 3)
weight <- c(4.4, 5.3, 7.2, 5.2, 8.5, 7.3, 6, 10.4, 10.2, 6.1)
plot(age, weight)  
abline(lm(age~weight))  ##��Ӳο���
title("Regression of age on weight") #��ӱ���


##��ͼƬ����Ϊpdf
pdf("mygraph.pdf") # width, height���趨
plot(age, weight)  
abline(lm(age~weight))
title("Regression of age on weight") 
dev.off()  #�ر�ͼ���豸

##����Ϊ������ʽ�ļ���png(), jpeg(), bmp(), tiff(), xfig()


rm(list = ls()) #��ջ��������б���
dev.off()
##
##ͼ�β�������par()
##lwd ָ���������
##cex ָ�����Ŵ�С
##lty ָ����������
##pch ָ����ͼʱ�ķ���
##col ��ͼ��ɫ
##xlim ylim ָ��x��y�����귶Χ
##font.lab ���������Ƶ�������ʽ
#pdf("drug_response.pdf")
dose <- c(20, 30, 40, 45, 60)
drugA <- c(16, 20, 27, 40, 60)
drugB <- c(15, 18, 25, 31, 40)
opar <- par(no.readonly = TRUE) #����һ�����޸ĵĵ�ǰͼ�β����б�
par(lwd = 2, cex = 1.5, font.lab = 2) #par ͼ�β�������
plot(dose, drugA, type = "b", pch = 15, lty = 1, col = "red", 
    ylim = c(0, 60), main = "Drug A vs. Drug B", xlab = "Drug Dosage", 
    ylab = "Drug Response")
lines(dose, drugB, type = "b", pch = 17, lty = 2, 
    col = "blue")

#���ͼ��
legend("topleft", inset = 0.05, title = "Drug Type", 
    c("A", "B"), lty = c(1, 2), pch = c(15, 17), col = c("red","blue"))
par(opar)
dev.off()

rm(list = ls()) #��ջ��������б���
dev.off()

##ֱ��ͼ&����ͼ&С����ͼ
##�������ݼ�mtcars
#wt ��������
#mpg ÿ����������ʻ��Ӣ����
attach(mtcars)
hist(wt, main = "Histogram of wt")  ##ֱ��ͼ����
boxplot(wt, main = "Boxplot of wt") ##����ͼ����
library(vioplot)  ##����vioplot��
vioplot(wt,main = "Boxplot of wt")  ##С����ͼ

rm(list = ls()) #��ջ��������б���
dev.off()

##ͼ�ε����,����ͼ����Ϊһ��ͼ
##par()������ ����mfrow=c(nrows,ncols)�����������ģ�����Ϊnrows������Ϊncols��ͼ�ξ���
pdf("combination_plot.pdf")
attach(mtcars)
opar <- par(no.readonly = TRUE)
par(mfrow = c(2, 2))  ##���������Ų�
plot(wt, mpg, main = "Scatterplot of wt vs. mpg")
plot(wt, disp, main = "Scatterplot of wt vs disp")
hist(wt, main = "Histogram of wt")
boxplot(wt, main = "Boxplot of wt")
par(opar)
detach(mtcars)
dev.off()


##�Ƽ�ggplot2��ͼ
##

##Τ��ͼ
##���������İ�
library(grid)
library(futile.logger)
library(VennDiagram)
##�����������
venn.plot <- draw.pairwise.venn(
area1 = 15, #��һ������С
area2 = 20, #�ڶ�������С
cross.area = 8, #�������Ľ�����С
fill = c("blue", "yellow"), #����Ӧ��Ȧ�����ɫ
lty = "blank", #Բ�ܵ���������
cex = 3, #Τ��ͼ�����������ǩע�������С
cat.cex = 3, #���������С
);

pdf(filename = "VennDiag.tiff");
grid.draw(venn.plot);
dev.off()

##�������ݼ���venn.plot <- draw.triple.venn()
##�ĸ����ݼ���venn.plot <- draw.quad.venn()

