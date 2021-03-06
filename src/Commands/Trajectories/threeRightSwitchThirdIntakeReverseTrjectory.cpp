#include "Commands/MotionProfile.h"
namespace ThreeRightSwitchThirdIntakeReverseTrajectories
{

extern const unsigned int kTrajectoryLength = 112;

extern const robovikes::TrajectoryPoint rightTrajectories[] = {
  // { position (R), velocity (RPM) },
  { -0.157002, -3.14003 },
  { -0.785008, -6.28006 },
  { -2.19802, -14.1301 },
  { -4.71005, -25.1203 },
  { -8.63509, -39.2504 },
  { -14.2871, -56.5206 },
  { -21.9802, -76.9308 },
  { -32.0283, -100.481 },
  { -44.7455, -127.171 },
  { -60.4456, -157.002 },
  { -79.4428, -189.972 },
  { -102.051, -226.082 },
  { -128.584, -265.333 },
  { -159.357, -307.723 },
  { -194.682, -353.254 },
  { -234.874, -401.924 },
  { -280.248, -453.735 },
  { -331.116, -508.685 },
  { -387.794, -566.776 },
  { -450.595, -628.006 },
  { -519.832, -692.377 },
  { -595.821, -759.888 },
  { -678.875, -830.538 },
  { -769.308, -904.329 },
  { -867.434, -981.260 },
  { -973.567, -1061.33 },
  { -1088.02, -1144.54 },
  { -1210.95, -1229.32 },
  { -1342.36, -1314.10 },
  { -1482.09, -1397.31 },
  { -1629.83, -1477.38 },
  { -1785.27, -1554.32 },
  { -1948.08, -1628.11 },
  { -2117.95, -1698.76 },
  { -2294.58, -1766.27 },
  { -2477.64, -1830.64 },
  { -2666.83, -1891.87 },
  { -2861.82, -1949.96 },
  { -3062.32, -2004.91 },
  { -3267.99, -2056.72 },
  { -3478.53, -2105.39 },
  { -3693.62, -2150.92 },
  { -3912.95, -2193.31 },
  { -4136.21, -2232.56 },
  { -4363.07, -2268.67 },
  { -4593.24, -2301.64 },
  { -4826.39, -2331.47 },
  { -5062.20, -2358.16 },
  { -5300.37, -2381.71 },
  { -5540.59, -2402.12 },
  { -5782.53, -2419.39 },
  { -6025.88, -2433.52 },
  { -6270.33, -2444.51 },
  { -6515.57, -2452.36 },
  { -6761.27, -2457.07 },
  { -7006.99, -2457.18 },
  { -7252.26, -2452.69 },
  { -7496.77, -2445.06 },
  { -7740.20, -2434.29 },
  { -7982.23, -2420.37 },
  { -8222.56, -2403.32 },
  { -8460.88, -2383.13 },
  { -8696.86, -2359.79 },
  { -8930.19, -2333.32 },
  { -9160.56, -2303.71 },
  { -9387.65, -2270.96 },
  { -9611.16, -2235.06 },
  { -9830.76, -2196.03 },
  { -10046.1, -2153.86 },
  { -10257.0, -2108.54 },
  { -10463.0, -2060.09 },
  { -10663.9, -2008.50 },
  { -10859.2, -1953.76 },
  { -11048.8, -1895.89 },
  { -11232.3, -1834.88 },
  { -11409.4, -1770.72 },
  { -11579.7, -1703.43 },
  { -11743.0, -1633.00 },
  { -11899.0, -1559.42 },
  { -12047.2, -1482.71 },
  { -12187.5, -1402.86 },
  { -12319.5, -1319.86 },
  { -12443.0, -1235.19 },
  { -12558.1, -1150.41 },
  { -12664.8, -1067.09 },
  { -12763.5, -986.804 },
  { -12854.4, -909.655 },
  { -12938.0, -835.647 },
  { -13014.5, -764.779 },
  { -13084.2, -697.051 },
  { -13147.4, -632.463 },
  { -13204.5, -571.015 },
  { -13255.8, -512.707 },
  { -13301.6, -457.539 },
  { -13342.1, -405.511 },
  { -13377.8, -356.623 },
  { -13408.9, -310.875 },
  { -13435.7, -268.268 },
  { -13458.6, -228.800 },
  { -13477.8, -192.472 },
  { -13493.7, -159.284 },
  { -13506.7, -129.237 },
  { -13516.9, -102.329 },
  { -13524.7, -78.5613 },
  { -13530.5, -57.9337 },
  { -13534.6, -40.4461 },
  { -13537.2, -26.0986 },
  { -13538.7, -14.8910 },
  { -13539.4, -6.82356 },
  { -13539.6, -1.89612 },
  { -13539.6, -0.108700 },
  { -13539.6, -0.00000 }
};
extern const robovikes::TrajectoryPoint leftTrajectories[] = {
  // { position (R), velocity (RPM) },
  { -0.157002, -3.14003 },
  { -0.785008, -6.28006 },
  { -2.19802, -14.1301 },
  { -4.71005, -25.1203 },
  { -8.63509, -39.2504 },
  { -14.2871, -56.5206 },
  { -21.9802, -76.9308 },
  { -32.0283, -100.481 },
  { -44.7455, -127.171 },
  { -60.4456, -157.002 },
  { -79.4428, -189.972 },
  { -102.051, -226.082 },
  { -128.584, -265.333 },
  { -159.357, -307.723 },
  { -194.682, -353.254 },
  { -234.874, -401.924 },
  { -280.248, -453.735 },
  { -331.116, -508.685 },
  { -387.794, -566.776 },
  { -450.595, -628.006 },
  { -519.832, -692.377 },
  { -595.821, -759.888 },
  { -678.875, -830.538 },
  { -769.308, -904.329 },
  { -867.434, -981.260 },
  { -973.567, -1061.33 },
  { -1088.02, -1144.54 },
  { -1210.95, -1229.32 },
  { -1342.36, -1314.10 },
  { -1482.09, -1397.31 },
  { -1629.83, -1477.38 },
  { -1785.27, -1554.32 },
  { -1948.08, -1628.11 },
  { -2117.95, -1698.76 },
  { -2294.58, -1766.27 },
  { -2477.64, -1830.64 },
  { -2666.83, -1891.87 },
  { -2861.82, -1949.96 },
  { -3062.32, -2004.91 },
  { -3267.99, -2056.72 },
  { -3478.53, -2105.39 },
  { -3693.62, -2150.92 },
  { -3912.95, -2193.31 },
  { -4136.21, -2232.56 },
  { -4363.07, -2268.67 },
  { -4593.24, -2301.64 },
  { -4826.39, -2331.47 },
  { -5062.20, -2358.16 },
  { -5300.37, -2381.71 },
  { -5540.59, -2402.12 },
  { -5782.53, -2419.39 },
  { -6025.88, -2433.52 },
  { -6270.33, -2444.51 },
  { -6515.57, -2452.36 },
  { -6761.27, -2457.07 },
  { -7006.99, -2457.18 },
  { -7252.26, -2452.69 },
  { -7496.77, -2445.06 },
  { -7740.20, -2434.29 },
  { -7982.23, -2420.37 },
  { -8222.56, -2403.32 },
  { -8460.88, -2383.13 },
  { -8696.86, -2359.79 },
  { -8930.19, -2333.32 },
  { -9160.56, -2303.71 },
  { -9387.65, -2270.96 },
  { -9611.16, -2235.06 },
  { -9830.76, -2196.03 },
  { -10046.1, -2153.86 },
  { -10257.0, -2108.54 },
  { -10463.0, -2060.09 },
  { -10663.9, -2008.50 },
  { -10859.2, -1953.76 },
  { -11048.8, -1895.89 },
  { -11232.3, -1834.88 },
  { -11409.4, -1770.72 },
  { -11579.7, -1703.43 },
  { -11743.0, -1633.00 },
  { -11899.0, -1559.42 },
  { -12047.2, -1482.71 },
  { -12187.5, -1402.86 },
  { -12319.5, -1319.86 },
  { -12443.0, -1235.19 },
  { -12558.1, -1150.41 },
  { -12664.8, -1067.09 },
  { -12763.5, -986.804 },
  { -12854.4, -909.655 },
  { -12938.0, -835.647 },
  { -13014.5, -764.779 },
  { -13084.2, -697.051 },
  { -13147.4, -632.463 },
  { -13204.5, -571.015 },
  { -13255.8, -512.707 },
  { -13301.6, -457.539 },
  { -13342.1, -405.511 },
  { -13377.8, -356.623 },
  { -13408.9, -310.875 },
  { -13435.7, -268.268 },
  { -13458.6, -228.800 },
  { -13477.8, -192.472 },
  { -13493.7, -159.284 },
  { -13506.7, -129.237 },
  { -13516.9, -102.329 },
  { -13524.7, -78.5613 },
  { -13530.5, -57.9337 },
  { -13534.6, -40.4461 },
  { -13537.2, -26.0986 },
  { -13538.7, -14.8910 },
  { -13539.4, -6.82356 },
  { -13539.6, -1.89612 },
  { -13539.6, -0.108700 },
  { -13539.6, -0.00000 }
};

} // namespace ThreeRightSwitchThirdIntakeReverseTrajectories
