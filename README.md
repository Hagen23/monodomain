Monodomain
==========

Solves the following monodomain equation by finite difference:

grad dot (sigma(grad(Vm))) = Im

where Vm is the transmembrane potential and Im is the transmembrane current, given by Im = beta(Cm(dVm/dt) + iion - stim).
beta is the surface-to-volume ratio, Cm is the membrane capacitance, iion is the ionic membrane current governed by the membrane model, and stim is an externally applied stimulus current.
  
Uses central difference approximation to calculate the diffusion term in the equations.
A forward euler time-stepping scheme is used for the diffusion term and the membrane model.
The model is solved for a 2D domain, with the boundary conditions set to zero.

The monodomain model can be used to test membrane models, before implementing them into the more realistic bidomain model.

Install
=======

run 'make' from command line in the working directory:

> make

this will produce an executable file named 'run', which can be ran from the command line with:

> ./run

The compiler flags in the Makefile can be edited if needed.

Model setup
===========

The parameters for the model are defined in the 'constants.h' file, such as membrane capacitance, surface-to-volume ratio, and membrane model parameters. 
The model setup is define in main.cc

Visualisation
=============

matplotlib is used to display the potentials:

> python3 plot.py
