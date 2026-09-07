# Vortex-Induced Vibration Screening of a Spar-Type Cylinder

## Project Overview

A CFD-based study of vortex-induced vibration (VIV) of a spar-type
floating offshore platform cylinder using ANSYS Fluent.

## Software Used

- ANSYS Fluent
- MATLAB

## Model

- Cylinder diameter: 10 m
- Fluid: Seawater
- Analysis: 2D transient CFD
- Solver: Pressure-based
- Turbulence model: SST k-ω
- Dynamic mesh: Six-DOF rigid-body motion

## Methodology

The flow around a circular cylinder is simulated using transient CFD.
Hydrodynamic lift and drag forces are obtained from ANSYS Fluent, while
the cylinder response and frequency characteristics are analyzed using
MATLAB.

## Files

- `vortex_6dof.c` – Six-DOF motion UDF used in Fluent
- `MATLAB/` – MATLAB analysis scripts
- `Results/` – Simulation plots and contours
- `Report.pdf` – Project report

## Objective

To investigate vortex shedding and screen the potential VIV response
of a spar-type offshore platform cylinder.
