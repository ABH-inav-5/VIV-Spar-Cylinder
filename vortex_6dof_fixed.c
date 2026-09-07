#include "udf.h"
#include "dynamesh_tools.h"

/*
 * 1-DOF transverse VIV model
 * X translation: fixed
 * Y translation: free
 * Rotation: fixed
 *
 * IMPORTANT:
 * MASS, STIFFNESS and DAMPING below are benchmark values.
 * Replace them with your chosen physical/screening values.
 *
 * For a 2D unit-span model, use mass/stiffness/damping
 * consistently per unit span.
 */

#define MASS       161012.0
#define STIFFNESS  0.0
#define DAMPING    0.0
#define Y0         319.923767

DEFINE_SDOF_PROPERTIES(vortex_6dof, prop, dt, time, dtime)
{
    real y;
    real vy;

    /* Current cylinder CG position and transverse velocity */
    y  = DT_CG(dt)[1] - Y0;
    vy = DT_VEL_CG(dt)[1];

    /* Structural properties */
    prop[SDOF_MASS] = MASS;

    /* Rotation is constrained, but inertia values are still supplied */
    prop[SDOF_IXX] = 1.0;
    prop[SDOF_IYY] = 1.0;
    prop[SDOF_IZZ] = 1.0;

    /* Allow only transverse (Y) translation */
    prop[SDOF_ZERO_TRANS_X] = TRUE;
    prop[SDOF_ZERO_TRANS_Y] = FALSE;
    prop[SDOF_ZERO_TRANS_Z] = TRUE;

    /* No rotation */
    prop[SDOF_ZERO_ROT_X] = TRUE;
    prop[SDOF_ZERO_ROT_Y] = TRUE;
    prop[SDOF_ZERO_ROT_Z] = TRUE;

    /*
     * Restoring + damping force in Y:
     *     F_y = -K*y - C*dy/dt
     *
     * The hydrodynamic force from the flow is handled by Fluent.
     * This term supplies the structural spring/damper force.
     */
    prop[SDOF_LOAD_F_Y] = -STIFFNESS * y - DAMPING * vy;

    /* No additional external forces/moments */
    prop[SDOF_LOAD_F_X] = 0.0;
    prop[SDOF_LOAD_F_Z] = 0.0;
    prop[SDOF_LOAD_M_X] = 0.0;
    prop[SDOF_LOAD_M_Y] = 0.0;
    prop[SDOF_LOAD_M_Z] = 0.0;
}
