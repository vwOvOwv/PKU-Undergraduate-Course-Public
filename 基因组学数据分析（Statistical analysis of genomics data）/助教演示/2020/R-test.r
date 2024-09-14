##概要
##R导入数据，保存数据
##R简单的作图命令


##设置工作路径
setwd("E:/20200929_Rstudio_test")

##导入文本文件（.txt文件）
age <- read.delim("age.txt", header=FALSE)

##导入逗号分隔文件（.csv文件）
weight <- read.csv("weight.csv", header=FALSE)

##导入excel文件（可以转成.csv格式）
#方法1
install.packages("RODBC") #通过RODBC包来访问excel
library(RODBC) #导入RODBC包
data <- odbcConnectExcel("file.xls") #odbcConnectExcel is only usable with 32-bit Windows
#方法2
install.packages("xlsx") #通过xlsx包来访问excel
library(xlsx) #导入xlsx包
data <- read.xlsx("file.xlsx")


##快速读取大量数据
install.packages("data.table") #安装data.table，解决处理较大数据集的问题
library(data.table)
data<- fread("Big_data.txt")

tmp_data <- age$V1 + weight$V1


##保存数据
write.table(tmp_data,file="tmp_data.txt",col.names=F) #保存为txt文件
write.csv(tmp_data,file="tmp_data.csv") #保存为csv文件
save(tmp_data,file="tmp_data.Rdata") #保存R文件，导入load("tmp_data.Rdata")，注意加引号


##常用的一些函数
#mode(age) #显示对象的类型
#names(age) #显示对象中的标签
#dim(age) #显示对象的维度
#mean(weight) #均值
#sd(weight)   #方差
#cor(age, weight) #相关性

rm(list = ls()) #清空环境中所有变量
# Ctrl + L 清空控制台


##检查数据中是否有缺失值
test_data <- c(1, 3, NA, 2, NA, 9, 3, 9, 12, 3)
is.na(test_data) #返回 TRUE or FALSE 
which(is.na(test_data)) #返回缺失值位置
sum(is.na(test_data))  #计算数据集的缺失值总数
data <- na.omit(test_data) #去掉缺失值

rm(list = ls()) #清空环境中所有变量


##散点图
age <- c(1, 3, 5, 2, 11, 9, 3, 9, 12, 3)
weight <- c(4.4, 5.3, 7.2, 5.2, 8.5, 7.3, 6, 10.4, 10.2, 6.1)
plot(age, weight)  
abline(lm(age~weight))  ##添加参考线
title("Regression of age on weight") #添加标题


##将图片保存为pdf
pdf("mygraph.pdf") # width, height可设定
plot(age, weight)  
abline(lm(age~weight))
title("Regression of age on weight") 
dev.off()  #关闭图形设备

##保存为其他格式文件：png(), jpeg(), bmp(), tiff(), xfig()


rm(list = ls()) #清空环境中所有变量
dev.off()
##
##图形参数函数par()
##lwd 指定线条宽度
##cex 指定符号大小
##lty 指定线条类型
##pch 指定绘图时的符号
##col 绘图颜色
##xlim ylim 指定x，y轴坐标范围
##font.lab 坐标轴名称的字体样式
#pdf("drug_response.pdf")
dose <- c(20, 30, 40, 45, 60)
drugA <- c(16, 20, 27, 40, 60)
drugB <- c(15, 18, 25, 31, 40)
opar <- par(no.readonly = TRUE) #生成一个可修改的当前图形参数列表
par(lwd = 2, cex = 1.5, font.lab = 2) #par 图形参数函数
plot(dose, drugA, type = "b", pch = 15, lty = 1, col = "red", 
    ylim = c(0, 60), main = "Drug A vs. Drug B", xlab = "Drug Dosage", 
    ylab = "Drug Response")
lines(dose, drugB, type = "b", pch = 17, lty = 2, 
    col = "blue")

#添加图例
legend("topleft", inset = 0.05, title = "Drug Type", 
    c("A", "B"), lty = c(1, 2), pch = c(15, 17), col = c("red","blue"))
par(opar)
dev.off()

rm(list = ls()) #清空环境中所有变量
dev.off()

##直方图&箱线图&小提琴图
##内置数据集mtcars
#wt 车身重量
#mpg 每加仑汽油行驶的英里数
attach(mtcars)
hist(wt, main = "Histogram of wt")  ##直方图函数
boxplot(wt, main = "Boxplot of wt") ##箱线图函数
library(vioplot)  ##导入vioplot包
vioplot(wt,main = "Boxplot of wt")  ##小提琴图

rm(list = ls()) #清空环境中所有变量
dev.off()

##图形的组合,多张图整合为一张图
##par()函数中 参数mfrow=c(nrows,ncols)创建按行填充的，行数为nrows，列数为ncols的图形矩阵
pdf("combination_plot.pdf")
attach(mtcars)
opar <- par(no.readonly = TRUE)
par(mfrow = c(2, 2))  ##两行两列排布
plot(wt, mpg, main = "Scatterplot of wt vs. mpg")
plot(wt, disp, main = "Scatterplot of wt vs disp")
hist(wt, main = "Histogram of wt")
boxplot(wt, main = "Boxplot of wt")
par(opar)
detach(mtcars)
dev.off()


##推荐ggplot2作图
##

##韦恩图
##导入依赖的包
library(grid)
library(futile.logger)
library(VennDiagram)
##具体参数设置
venn.plot <- draw.pairwise.venn(
area1 = 15, #第一个集大小
area2 = 20, #第二个集大小
cross.area = 8, #两个集的交集大小
fill = c("blue", "yellow"), #集对应的圈填充颜色
lty = "blank", #圆周的线条类型
cex = 3, #韦恩图各部分面积标签注释字体大小
cat.cex = 3, #集名字体大小
);

pdf(filename = "VennDiag.tiff");
grid.draw(venn.plot);
dev.off()

##三个数据集：venn.plot <- draw.triple.venn()
##四个数据集：venn.plot <- draw.quad.venn()

