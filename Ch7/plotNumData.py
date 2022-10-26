import matplotlib.pyplot as plt
from matplotlib.pylab import *
from numpy import *


def plotComparison():
    yexact = array([])
    #Forward Euler
    t1=array([])
    y1=array([])
    infile1=open('ForwEul_ty.dat','r')
    for line in infile1:
        words=line.split()
        t1=append(t1,float(words[0]))
        y1=append(y1,float(words[1]))
    infile1.close()

    #RK4
    t2 = array([])
    y2 = array([])
    infile2 = open('RK4_ty.dat', 'r')
    for line in infile2:
        words = line.split()
        t2 = append(t2, float(words[0]))
        y2 = append(y2, float(words[1]))
    infile2.close()

    yexact=append(yexact,(t1**2+2*t1+4)*0.5)

    plot(t1,y1,'b--')
    plot(t2,y2,'g-')
    plot(t1,yexact,'r-.')
    xlabel('t')
    ylabel('y')
    plt.legend(['Forward Euler','RK4','exact'])
    show()

if __name__=='__main__':
    plotComparison()