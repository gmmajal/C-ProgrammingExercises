import matplotlib.pyplot as plt
from matplotlib.pylab import *
from numpy import *

def plotComparison():
    x=array([])
    y=array([])
    yexact=array([])
    infile=open('xy.dat','r')
    for line in infile:
        words=line.split()
        x=append(x,float(words[0]))
        y=append(y,float(words[1]))
    infile.close()
    yexact=append(yexact,exp(-x))

    plot(x,y,'b--')
    plot(x,yexact,'r-.')
    xlabel('x')
    ylabel('y')
    plt.legend(['numerical','exact'])
    show()

if __name__=='__main__':
    plotComparison()