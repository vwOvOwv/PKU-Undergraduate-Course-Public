
rm(list = ls())
setwd("/lustre/user/liclab/liuyt/Genomic-Class")
# R Object Oriented -------------------------------------------------------

# I. object ---------------------------------------------------------------
x <- 1
class(x)
x <- 'genomic'
class(x)
x <- '1.5e23'
class(x)
x <- 'TRUE'
class(x)


a <- seq(1,9,1)
a
a <- matrix(data = seq(1,9,1), nrow = 3)
a
class(a)
dim(a)
b <- data.frame(a)
class(b)


# II. function ------------------------------------------------------------
# base function
# packages
# self-defined
x <- seq(1,9)
length(x)
?length
sum(x)
max(x)

library(stats)
quantile(x)
?quantile


FirstClass <- function(i){
  print(i)
}
FirstClass(1)



# III. stats and plot -----------------------------------------------------
x <- rnorm(10)
y <- rnorm(10)

# base plot function
plot(x,y)
plot(x, y, xlab="Ten random values", ylab="Ten other values",
     xlim=c(-2, 2), ylim=c(-2, 2), pch=22, col="red",
     bg="yellow", bty="l", tcl=0.4,
     main="How to customize a plot with R", las=1, cex=1.5)

?plot

# load data
mat <- read.xlsx("data/Demo1.FPKM.table1.xlsx", colNames = T, rowNames = T)
mat <- 2^mat

# base plot function
boxplot(mat[,1:3])
boxplot(log2(mat[,1:3]+1))

# ggplot: barplot
region.vec <- c(rep("CP",3), rep("GZ",3), rep("CP",3), rep("GZ",3), rep("CP",3), rep("GZ",3))
gname <- c('ENSMMUG00000008296','ENSMMUG00000016810')

caseplot <- function(gname){
  
  loci <- match(gname, rownames(mat))
  case.mat <- data.frame(region = region.vec, value = unlist(mat[loci,]))
  data_summary <- function(data, varname, groupnames){
    require(plyr)
    summary_func <- function(x, col){
      c(mean = mean(x[[col]], na.rm=TRUE),
        sd = sd(x[[col]], na.rm=TRUE))
    }
    data_sum<-ddply(data, groupnames, .fun=summary_func,
                    varname)
    data_sum <- rename(data_sum, c("mean" = varname))
    return(data_sum)
  }
  df2 <- data_summary(case.mat, varname="value", 
                      groupnames=c("region"))
  # Convert dose to a factor variable
  df2$region=as.factor(df2$region)
  
  linesize = 1
  fontsize = 8
  ggplot(df2, aes(x=region, y=value, fill=region)) + 
    geom_bar(stat="identity", 
             position=position_dodge(), width = .5) +
    geom_errorbar(aes(ymin=value-sd, ymax=value+sd), width=.2,
                  position=position_dodge(.9)) +
    labs(title=gname,  y = "FPKM")+
    theme_classic() +
    scale_fill_manual(values=c("CP" = rgb(131,133,187, maxColorValue = 255),"GZ" = rgb(242,189,62, maxColorValue = 255)))+
    #scale_fill_manual(values=c("CP" = "cornflowerblue","GZ" = "chartreuse3"))+
    theme_bw() +
    theme(panel.grid.major = element_blank(),panel.grid.minor = element_blank(),strip.background = element_blank(),panel.border = element_blank())+
    theme(axis.text.x = element_text(size=fontsize),axis.text.y = element_text(size=fontsize),  
          axis.title.x = element_text(size=fontsize),axis.title.y = element_text(size=fontsize),
          axis.line.y = element_line(colour = "black", size = linesize),axis.ticks.x=element_blank(),
          axis.line.x = element_line(colour = "black", size = linesize),
          axis.ticks.y = element_line(size = linesize),legend.text=element_text(size=fontsize),
          axis.ticks.length = unit(.05, "cm"),
          plot.title = element_text(size=fontsize, hjust = 0.5))
 
  
  
  
  
}

lapply(gname, caseplot)



# statistics examples: correlation and t test
cor.mat <- cor(mat, method = "pearson")
cor.mat
pheatmap(cor.mat)

t.test(mat[,1], mat[,18])
