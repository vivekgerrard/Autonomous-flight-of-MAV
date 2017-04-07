#!/usr/bin/python

#A python script to test the time to contact
#canny edge detector
import cv2
import numpy as np 
from numpy.linalg import inv
from matplotlib import pyplot as p


#Generate histogram of edges
def hist(grey):

	#Canny(image, min_value, max_value)
	edges = cv2.Canny(grey, 100, 330, True) 

	#Normalization
	temp_edges = edges/255 

	#sum of edge points in a column
	sofeature = 0 
	
	#Histogram of columns
	F1 = np.empty(width)

	for i in range(0,width-1):
		for j in range(0, length-1):
			sofeature = sofeature + temp_edges[j,i]
		F1[i] = sofeature
		sofeature = 0
	return F1

	


#Time to contact
image1 = cv2.imread('frame1962.jpg')
image2 = cv2.imread('frame1963.jpg')
grey1 = cv2.cvtColor(image1, cv2.COLOR_BGR2GRAY)
grey2 = cv2.cvtColor(image2, cv2.COLOR_BGR2GRAY)
length, width = grey1.shape[:2]	
print width
F = hist(grey2)
F1 = hist(grey1)
A11 = 0.0
A12 = 0.0
A22 = 0.0
C1 = 0.0
C2 = 0.0
for k in range(1,width-1):
	Ft = (F1[k] - F[k])*30
	Ft = np.asscalar(Ft)
	Fx = F1[k] - F1[k-1] 
	Fx = np.asscalar(Fx)	
	A11 = A11 + (pow(Fx,2)*pow(k,2))
	A12 = A12 + (pow(Fx,2)*k)
	A22 = A22 + pow(Fx,2)
	C1 = C1 + (Fx*Ft*k)
	C2 = C2 + (Fx*Ft)

A = np.array([[A11, A12], [A12, A22]])
C = np.array([[C1],[C2]])

B = np.dot(inv(A),C)
	
#F = F1	
print B

#Rate of expansion
#a=B[1]+1

#Time to contact
#t = a/(a-1)

