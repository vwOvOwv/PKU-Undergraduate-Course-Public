from scipy.integrate import odeint
import numpy as np
import matplotlib.pyplot as plt

# Define the system of differential equations
def system(N, t, r1, r2, r3, K1, K2, K3, a11, a12, a13, a21, a22, a23, a31, a32, a33, d1, d2, d3):
    N1, N2, N3 = N
    dN1_dt = r1 * N1 * (1 - a11 * N1 / K1 - a21 * N2 / K1 - a31 * N3 / K1) - d1 * N1
    dN2_dt = r2 * N2 * (1 - a12 * N1 / K2 - a22 * N2 / K2 - a32 * N3 / K2) - d2 * N2
    dN3_dt = r3 * N3 * (1 - a13 * N1 / K3 - a23 * N2 / K3 - a33 * N3 / K3) - d3 * N3
    return [dN1_dt, dN2_dt, dN3_dt]

# Parameters (example values)
r1, r2, r3 = 0.05, 0.12, 0.1
K1, K2, K3 = 20, 50, 50
d1, d2, d3 = 0.05, 0.025, 0.025
a11, a12, a13 = 0.9, 0.2, 0.2
a21, a22, a23 = 0.5, 1, 0.8
a31, a32, a33 = 0.5, 0.8, 1

# Initial conditions
N0 = [0, 4, 4]  # Example initial conditions for N1, N2, N3

# Time vector
t = np.linspace(0, 150, 1000)  # Time from 0 to 100 divided into 1000 points

# Solve the system of differential equations
solution = odeint(system, N0, t, args=(r1, r2, r3, K1, K2, K3, a11, a12, a13, a21, a22, a23, a31, a32, a33, d1, d2, d3))

# Plot the results
plt.figure(figsize=(12, 8))
plt.plot(t, solution[:, 0], label='N1(t)')
plt.plot(t, solution[:, 1], label='N2(t),N2(0)=4')
plt.plot(t, solution[:, 2], label='N3(t),N3(0)=4')

plt.title('N-t Curves')
plt.xlabel('Time')
plt.ylabel('Population')
plt.legend()
plt.grid(True)
plt.show()