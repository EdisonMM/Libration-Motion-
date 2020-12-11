#!/usr/bin/env python
# coding: utf-8

# In[1]:


from numpy import *


# In[23]:


m = 1
M = 60
R = 1
w = 1
k = m/M
lamda = k/(1 + k)
rm = (1 - lamda) * R
rM = lamda*R


# In[24]:


def fx(x, y, rm, rM):
    
    A = -w**2 * R**2
    
    B = (x + rM)*rm
    
    C = (y**2 + (x + rM)**2)**3/2
    
    D = (x - rm)*rM
    
    E = (y**2 + (x - rm)**2)**3/2
    
    return A * (B/C + D/E)

def fy(x, y, rm, rM):
    
    A = -w**2 * R**2
    
    B = y*rm
    
    C = (y**2 + (x + rM)**2)**(3/2)
    
    D = y*rM
    
    E = (y**2 + (x - rm)**2)**(3/2)
    
    return A * (B/C + D/E)


# In[25]:


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


# In[26]:


def canon_ball(t0, tf, N, xinit, yinit):
    
    """This function solves the canon ball equations of motion with air resistance using Runge Kunta"""
    
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
        


# In[32]:


x4 = (R/2) * (1 - k)/(1 + k)
y4 = R*sin(pi/3)


# In[33]:


t, x, y, u, v = canon_ball(0, 100, 1000, x4, y4)


# In[34]:


from matplotlib import pyplot as plt


# In[35]:


plt.plot(x,y)


# In[37]:


from scipy.integrate import solve_ivp


# In[40]:


def fdot(t, r):
    
    x, y, u, v = r
    
    udot = fx(x,y,rm,rM) + 2*w*v + (w**2) * x
    
    vdot = fy(x,y,rm,rM) - 2*w*u + (w**2) * y
    
    return [u, v, udot, vdot]


# In[41]:


init_cond = [x4, y4, 0, 0]
sol = solve_ivp(fdot, [0, 100], init_cond)


# In[44]:


x = sol.y[0]
y = sol.y[1]

plt.plot(x,y)


# In[ ]:




