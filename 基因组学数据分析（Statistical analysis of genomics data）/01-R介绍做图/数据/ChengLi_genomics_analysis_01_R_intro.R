# start R GUI (on Unix, type "R")
# change working directory (File/Change dir) ("Misc" diectory on Mac)
# load this file (File/Open script)

# Control+R(Windows) or Command+Enter(Mac) to run a line or selected lines
# Up or Down arrows to modify previous commands

# '#' starts a comment line

# R basics

# R handles entire data vectors as single objects

weight <- c(60, 72, 57, 90, 95, 72) # construct c(...) to define vectors
weight

# there are other ways to read in data

# arithmetic operations of the vectors of the same legnth: element-wise 

height <- c(1.75, 1.80, 1.65, 1.90, 1.74, 1.91)
bmi <- weight / height^2 
# weight in kg, height in m; if using lb and ft, multiply by 4.88

bmi

# statistical functions & plotting

t.test(bmi, mu=22.5)

plot(height, weight)

plot(height, weight, pch=2) # change 'plotting character'

# add a line of "normal" weight = 22.5 * height^2

height.new <- seq(from=1.65, to=1.9, by=0.05)
weight.new <- 22.5 * height.new^2
lines(height.new, weight.new)

# other built-in functions

ls()   # list the objects in the current working space

var(height)   # variance

summary(height)    # summary statistics

# Use the File menu to save and load working space



### flow control


### slide: Fibonacci sequence

Fibonacci <- numeric(12) # allocate vector variable
Fibonacci 

## Student question 2014.4: why not numeric(0)?
Fibonacci[1]
Fibonacci[1] <- 1
Fibonacci[1] 
Fibonacci

Fibonacci[2] <- 1
Fibonacci 

Fibonacci[3] <- Fibonacci[1] + Fibonacci[2]
Fibonacci[3]
Fibonacci

Fibonacci[4] <- Fibonacci[2] + Fibonacci[3]
Fibonacci[4]
Fibonacci

Fibonacci[5] <- Fibonacci[3] + Fibonacci[4]
Fibonacci[5]
Fibonacci

3:12

paste("Fib", 2, "=", Fibonacci[2])

for (i in 3:12) {
	Fibonacci[i] <- Fibonacci[i - 2] + Fibonacci[i - 1]
    print(paste("Fib", i, "=", Fibonacci[i]) )
}
i

Fibonacci


### another for() example

x <- seq(0, 1, .05)
plot(x, x, ylab="y", type="l")
for (i in 2:8) {
	lines(x, x^i)
}


### slide: while loop

x.total <- 0
x.count <- 0
while (x.total < 100) {
	x.total <- x.total + runif(1)
	x.count <- x.count + 1
}

list(total=x.total, count=x.count)


### slide: Example: Newton's method for root finding

x0 <- 1

x <- x0
f <- x^3 + 2 * x^2 - 7
tolerance <- 0.000001

while (abs(f) > tolerance) {
  f.prime <- 3 * x^2 + 4 * x
  x <- x - f / f.prime
  f <- x^3 + 2 * x^2 - 7
  print(x)
}

x

# confirm with plot

curve(x^3 + 2 * x^2 - 7, -5, 5)
abline(h = 0, col = "blue")
abline(v = x, col = "red")



### Buffon's needle, Cheng Li's code

# assume lines are horizontal at integers
par(mar=c(2,2,2,2))
plot(0:10, 0:10, type="n", xlab="", ylab="", asp=1)
abline(h=0:10)

# drop a random line with length 1

set.seed(10000) # random seed

one_trial <- function() {

  rand.point.x <- runif(1) * 8 + 1 # random value in [1,9]
  rand.point.y <- runif(1) * 8 + 1 # random value in [1,9]

  rand.angle <- runif(1) * 2 * pi   # random angle in [0,2*Pi]
  end.point.x <- rand.point.x + cos(rand.angle) * 1
  end.point.y <- rand.point.y + sin(rand.angle) * 1

  lines(c(rand.point.x, end.point.x), c(rand.point.y, end.point.y))
  intersected <- floor(rand.point.y) != floor(end.point.y)

  intersected
}

num.trial = 100

#num.trial = 10000

buffon.trial <- replicate(num.trial, one_trial())

prob.intersect <- sum(buffon.trial) / num.trial
pi.estimate = 2 / prob.intersect 

print(paste("my estimate of pi is", pi.estimate, "after", num.trial, "trials"))


######### R graphs

x <- seq(0, 1, .05)
plot(x, x, ylab="y", type="l")

for (i in 2:8)
    lines(x, x^i, col=i, lwd=i)

example(plot)
example(boxplot)
example(hist)
example(persp)
