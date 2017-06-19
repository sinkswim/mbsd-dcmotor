# mbsd-dcmotor
Model-based SW design of a DC motor controller for code generation.

Starting from a Simulink model describing a DC motor system (controller and plant in feedback), C code has been generated and integrated in the Micrium uC/OS-III real-time operating system. It was then deployed on the Freedom K64F board by Freescale (NXP). A back-to-back test was then performed between the HW-in-the-Loop and Model-in-the-Loop simulations (on MATLAB).
In addition, the system has been verified with real-time simulations resorting to the National Instruments' myRIO device and Veristand.
Finally, a test set was defined in order to reach 100% of statement, branch and MCDC coverage.
