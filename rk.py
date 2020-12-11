from numpy import *

# defining parameters
m = 1
M = 60
R = 1
w = 1
k = m/M
lamda = k/(1 + k)
rm = (1 - lamda) * R
rM = lamda*R

# defining the Newton's differential equations of motion

def fx(x, y, rm, rM):
    
    A = -w**2 * R**2
    
    B = (x + rM)*rm
    
    C = (y**2 + (x + rM)**2)**(3/2)
    
    D = (x - rm)*rM
    
    E = (y**2 + (x - rm)**2)**(3/2)
    
    return A * (B/C + D/E)

def fy(x, y, rm, rM):
    
    A = -w**2 * R**2
    
    B = y*rm
    
    C = (y**2 + (x + rM)**2)**(3/2)
    
    D = y*rM
    
    E = (y**2 + (x - rm)**2)**(3/2)
    
    return A * (B/C + D/E)



def f(r, t):
    x = r[0]
    y = r[1]
    u = r[2]
    v = r[3]
    
    xdot = u
    ydot = v
    
    udot = fx(x,y,rm,rM) + 2*w*v + (w**2) * x
    
    vdot = fy(x,y,rm,rM) - 2*w*u + (w**2) * y
    
    return array([xdot, ydot, udot, vdot], float)


# implementing 4th order runge kutta
def rk(t0, tf, N, xinit, yinit):
    
    """This function solves the equation of motion for the circular restricted three body problem 
    using Runge Kunta 4th order"""
    
    h = (tf - t0)/N
    
    tpoints = arange(t0, tf, h)
    xpoints = []
    ypoints = []
    upoints = []
    vpoints = []
    
    r = array([xinit, yinit, 0, 0])
    
    for t in tpoints:
        
        xpoints.append(r[0])
        ypoints.append(r[1])
        upoints.append(r[2])
        vpoints.append(r[3])
        
        k1 = h * f(r, t)
        
        k2 = h * f(r + 0.5 * k1, t + 0.5*h)
        
        k3 = h * f(r + 0.5 * k2, t + 0.5*h)
        
        k4 = h * f(r + k3, t + h)
        
        new_term = (k1 + 2*k2 + 2*k3 + k4)/6
        
        r += (k1 + 2*k2 + 2*k3 + k4)/6
    
    
    return tpoints, xpoints, ypoints, upoints, vpoints
        

#x4 = (R/2) * (1 - k)/(1 + k)
#y4 = R*sin(pi/3)

# getting the coordinates of L4 and L5
x4 = R/2
y4 = R/2*sqrt(3)

x5 = x4
y5 = -y4


def write_results(x,y,outfile):

    """This function writes the orbit calculated on csv file arranged as x, y"""

    with open(outfile, 'w') as f:

        for i in range(len(x)):

            f.write("{0}, {1}\n".format(x[i], y[i]))

 
def get_orbit(xl, yl, outfile):

    """ This function computes the orbit in time interval t0, tmax, with initial positions xl,yl, 
    and zero velocities. It writes the result in outfile in csv format. 
    The columns are x, and y."""

    t, x, y, u, v = rk(0, 70, 1000, xl, yl)

    x = x + ones(len(x))*rM

    write_results(x, y, outfile)

# computing the orbits near L4 and L5
get_orbit(x4, y4, "l4.csv")
get_orbit(x5, y5, "l5.csv")