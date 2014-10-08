######################################
#                                    #
# Display results with matplotlib    # 
# Reads an output file into a numpy  # 
# array and displays scalar field.   #
# Uses python3.		             # 
#				     #
######################################

import numpy as np
import matplotlib.pyplot as plt

#read file into numpy array
a=np.genfromtxt('Vm.out.txt', dtype='double')
print(a.shape)
fig=plt.figure()
ims=[]

#step through each time-step and display image
for i in range(20):
    b=a[i,:].reshape((100,100)) 
    #get correct orientation with b.T (i.e. transpose)
    im=plt.imshow(b.T, interpolation='bilinear', extent=[0,1,0, 1], vmin=0, vmax=100)
    ims.append([im])
    plt.pause(0.1)
#plt.show()
