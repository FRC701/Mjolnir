#include "Commands/MotionProfile.h"
namespace LeftScaleTrajectories
{

extern const unsigned int kTrajectoryLength = 424;

extern const robovikes::TrajectoryPoint leftTrajectories[] = {
  // { position (R), velocity (RPM) },
  { 0.158261, 3.16522 },
  { 0.185541, 0.272801 },
  { 0.874422, 6.88881 },
  { 3.29748, 24.2306 },
  { 7.08352, 37.8604 },
  { 12.5354, 54.5192 },
  { 19.9562, 74.2071 },
  { 29.6486, 96.9242 },
  { 41.9157, 122.671 },
  { 57.0604, 151.447 },
  { 75.3858, 183.254 },
  { 97.1948, 218.091 },
  { 122.791, 255.959 },
  { 152.477, 296.858 },
  { 186.556, 340.790 },
  { 225.331, 387.755 },
  { 269.107, 437.754 },
  { 318.185, 490.789 },
  { 372.871, 546.859 },
  { 433.468, 605.967 },
  { 500.279, 668.114 },
  { 573.610, 733.302 },
  { 653.763, 801.533 },
  { 741.044, 872.807 },
  { 835.757, 947.129 },
  { 938.206, 1024.50 },
  { 1048.70, 1104.92 },
  { 1167.39, 1186.88 },
  { 1294.27, 1268.87 },
  { 1429.36, 1350.88 },
  { 1572.65, 1432.92 },
  { 1724.15, 1514.98 },
  { 1883.86, 1597.09 },
  { 2051.78, 1679.22 },
  { 2227.92, 1761.39 },
  { 2412.28, 1843.60 },
  { 2604.86, 1925.84 },
  { 2805.68, 2008.13 },
  { 3014.72, 2090.46 },
  { 3232.01, 2172.83 },
  { 3457.53, 2255.25 },
  { 3691.30, 2337.72 },
  { 3933.33, 2420.24 },
  { 4183.61, 2502.81 },
  { 4442.15, 2585.43 },
  { 4708.96, 2668.11 },
  { 4984.05, 2750.85 },
  { 5267.41, 2833.65 },
  { 5559.06, 2916.51 },
  { 5859.00, 2999.43 },
  { 6167.09, 3080.89 },
  { 6483.03, 3159.38 },
  { 6806.52, 3234.88 },
  { 7137.26, 3307.41 },
  { 7474.96, 3376.94 },
  { 7819.30, 3443.49 },
  { 8170.01, 3507.06 },
  { 8526.77, 3567.62 },
  { 8889.29, 3625.20 },
  { 9257.27, 3679.78 },
  { 9630.41, 3731.35 },
  { 10008.4, 3779.92 },
  { 10390.9, 3825.49 },
  { 10777.8, 3868.04 },
  { 11168.5, 3907.58 },
  { 11562.9, 3944.10 },
  { 11960.7, 3977.60 },
  { 12361.5, 4008.07 },
  { 12765.0, 4035.51 },
  { 13171.0, 4059.91 },
  { 13579.2, 4081.28 },
  { 13989.1, 4099.60 },
  { 14400.6, 4114.88 },
  { 14813.3, 4127.10 },
  { 15226.9, 4136.27 },
  { 15641.2, 4142.37 },
  { 16055.7, 4145.41 },
  { 16470.4, 4146.91 },
  { 16885.3, 4148.41 },
  { 17300.2, 4149.92 },
  { 17715.4, 4151.42 },
  { 18130.7, 4152.92 },
  { 18546.1, 4154.42 },
  { 18961.7, 4155.93 },
  { 19377.5, 4157.43 },
  { 19793.3, 4158.93 },
  { 20209.4, 4160.43 },
  { 20625.6, 4161.93 },
  { 21041.9, 4163.42 },
  { 21458.4, 4164.92 },
  { 21875.1, 4166.42 },
  { 22291.8, 4167.91 },
  { 22708.8, 4169.41 },
  { 23125.9, 4170.90 },
  { 23543.1, 4172.39 },
  { 23960.5, 4173.88 },
  { 24378.0, 4175.37 },
  { 24795.7, 4176.86 },
  { 25213.6, 4178.35 },
  { 25631.6, 4179.84 },
  { 26049.7, 4181.32 },
  { 26468.0, 4182.80 },
  { 26886.4, 4184.28 },
  { 27305.0, 4185.76 },
  { 27723.7, 4187.24 },
  { 28142.6, 4188.72 },
  { 28561.6, 4190.19 },
  { 28980.7, 4191.67 },
  { 29400.1, 4193.14 },
  { 29819.5, 4194.61 },
  { 30239.1, 4196.08 },
  { 30658.9, 4197.55 },
  { 31078.8, 4199.01 },
  { 31498.8, 4200.48 },
  { 31919.0, 4201.94 },
  { 32339.4, 4203.40 },
  { 32759.9, 4204.86 },
  { 33180.5, 4206.32 },
  { 33601.3, 4207.78 },
  { 34022.2, 4209.23 },
  { 34443.3, 4210.69 },
  { 34864.5, 4212.14 },
  { 35285.8, 4213.59 },
  { 35707.3, 4215.04 },
  { 36129.0, 4216.48 },
  { 36550.8, 4217.93 },
  { 36972.7, 4219.37 },
  { 37394.8, 4220.82 },
  { 37817.0, 4222.26 },
  { 38239.4, 4223.70 },
  { 38661.9, 4225.14 },
  { 39084.6, 4226.58 },
  { 39507.4, 4228.01 },
  { 39930.3, 4229.45 },
  { 40353.4, 4230.88 },
  { 40776.6, 4232.31 },
  { 41200.0, 4233.75 },
  { 41623.5, 4235.18 },
  { 42047.2, 4236.61 },
  { 42471.0, 4238.03 },
  { 42894.9, 4239.46 },
  { 43319.0, 4240.89 },
  { 43743.3, 4242.31 },
  { 44167.6, 4243.74 },
  { 44592.1, 4245.16 },
  { 45016.8, 4246.58 },
  { 45441.6, 4248.00 },
  { 45866.5, 4249.43 },
  { 46291.6, 4250.85 },
  { 46716.9, 4252.26 },
  { 47142.2, 4253.68 },
  { 47567.7, 4255.10 },
  { 47993.4, 4256.52 },
  { 48419.2, 4257.94 },
  { 48845.1, 4259.35 },
  { 49271.2, 4260.77 },
  { 49697.4, 4262.19 },
  { 50123.8, 4263.60 },
  { 50550.3, 4265.02 },
  { 50976.9, 4266.43 },
  { 51403.7, 4267.85 },
  { 51830.6, 4269.26 },
  { 52257.7, 4270.68 },
  { 52684.9, 4272.09 },
  { 53112.3, 4273.50 },
  { 53539.7, 4274.92 },
  { 53967.4, 4276.33 },
  { 54395.2, 4277.75 },
  { 54823.1, 4279.16 },
  { 55251.1, 4280.58 },
  { 55679.3, 4281.99 },
  { 56107.7, 4283.41 },
  { 56536.1, 4284.82 },
  { 56964.8, 4286.24 },
  { 57393.5, 4287.66 },
  { 57822.4, 4289.07 },
  { 58251.5, 4290.49 },
  { 58680.7, 4291.91 },
  { 59110.0, 4293.33 },
  { 59539.5, 4294.75 },
  { 59969.1, 4296.17 },
  { 60398.9, 4297.59 },
  { 60828.8, 4299.01 },
  { 61258.8, 4300.43 },
  { 61689.0, 4301.85 },
  { 62119.3, 4303.28 },
  { 62549.8, 4304.70 },
  { 62980.4, 4306.13 },
  { 63411.2, 4307.55 },
  { 63842.1, 4308.98 },
  { 64273.1, 4310.41 },
  { 64704.3, 4311.84 },
  { 65135.6, 4313.27 },
  { 65567.1, 4314.70 },
  { 65998.7, 4316.14 },
  { 66430.5, 4317.57 },
  { 66862.4, 4319.01 },
  { 67294.4, 4320.45 },
  { 67726.6, 4321.88 },
  { 68158.9, 4323.32 },
  { 68591.4, 4324.77 },
  { 69024.0, 4326.21 },
  { 69456.8, 4327.65 },
  { 69889.7, 4329.10 },
  { 70322.7, 4330.54 },
  { 70755.9, 4331.99 },
  { 71189.3, 4333.44 },
  { 71622.8, 4334.89 },
  { 72056.4, 4336.35 },
  { 72490.2, 4337.80 },
  { 72924.1, 4339.26 },
  { 73358.2, 4340.72 },
  { 73792.4, 4342.17 },
  { 74226.8, 4343.64 },
  { 74661.3, 4345.10 },
  { 75095.9, 4346.56 },
  { 75530.7, 4348.03 },
  { 75965.7, 4349.49 },
  { 76400.8, 4350.96 },
  { 76836.0, 4352.43 },
  { 77271.4, 4353.90 },
  { 77707.0, 4355.38 },
  { 78142.6, 4356.85 },
  { 78578.5, 4358.33 },
  { 79014.5, 4359.81 },
  { 79450.6, 4361.29 },
  { 79886.9, 4362.77 },
  { 80323.3, 4364.25 },
  { 80759.9, 4365.73 },
  { 81196.6, 4367.22 },
  { 81633.5, 4368.70 },
  { 82070.5, 4370.19 },
  { 82507.6, 4371.68 },
  { 82945.0, 4373.17 },
  { 83382.4, 4374.66 },
  { 83820.0, 4376.16 },
  { 84257.8, 4377.65 },
  { 84695.7, 4379.14 },
  { 85133.8, 4380.64 },
  { 85572.0, 4382.14 },
  { 86010.4, 4383.64 },
  { 86448.9, 4385.13 },
  { 86887.5, 4386.63 },
  { 87326.3, 4388.13 },
  { 87765.3, 4389.64 },
  { 88204.4, 4391.14 },
  { 88643.7, 4392.64 },
  { 89083.1, 4394.14 },
  { 89522.7, 4395.64 },
  { 89962.4, 4397.15 },
  { 90402.2, 4398.65 },
  { 90842.3, 4400.15 },
  { 91282.4, 4401.66 },
  { 91722.7, 4403.16 },
  { 92163.2, 4404.66 },
  { 92603.8, 4406.17 },
  { 93044.6, 4407.67 },
  { 93485.5, 4409.17 },
  { 93926.6, 4410.67 },
  { 94367.8, 4412.17 },
  { 94809.2, 4413.67 },
  { 95250.7, 4415.17 },
  { 95692.3, 4416.66 },
  { 96134.2, 4418.16 },
  { 96576.1, 4419.65 },
  { 97018.2, 4421.14 },
  { 97460.5, 4422.63 },
  { 97902.9, 4424.12 },
  { 98345.5, 4425.61 },
  { 98788.2, 4427.09 },
  { 99231.0, 4428.57 },
  { 99674.0, 4430.05 },
  { 100117, 4431.53 },
  { 100561, 4433.00 },
  { 101004, 4434.47 },
  { 101448, 4435.94 },
  { 101891, 4437.40 },
  { 102335, 4438.86 },
  { 102779, 4440.31 },
  { 103223, 4441.77 },
  { 103668, 4443.21 },
  { 104112, 4444.65 },
  { 104557, 4446.09 },
  { 105002, 4447.52 },
  { 105446, 4448.95 },
  { 105891, 4450.37 },
  { 106337, 4451.79 },
  { 106782, 4453.20 },
  { 107227, 4454.60 },
  { 107673, 4456.00 },
  { 108119, 4457.39 },
  { 108565, 4458.78 },
  { 109011, 4460.15 },
  { 109457, 4461.52 },
  { 109903, 4462.88 },
  { 110350, 4464.24 },
  { 110796, 4465.58 },
  { 111243, 4466.92 },
  { 111690, 4468.25 },
  { 112137, 4469.57 },
  { 112584, 4470.88 },
  { 113031, 4472.18 },
  { 113478, 4473.48 },
  { 113926, 4474.76 },
  { 114373, 4476.03 },
  { 114821, 4477.29 },
  { 115269, 4478.54 },
  { 115717, 4479.78 },
  { 116165, 4481.01 },
  { 116613, 4482.22 },
  { 117062, 4483.43 },
  { 117510, 4484.62 },
  { 117959, 4485.80 },
  { 118407, 4486.97 },
  { 118856, 4488.12 },
  { 119305, 4489.26 },
  { 119754, 4490.39 },
  { 120203, 4491.50 },
  { 120652, 4492.60 },
  { 121102, 4493.68 },
  { 121551, 4494.75 },
  { 122001, 4495.81 },
  { 122451, 4496.85 },
  { 122900, 4497.87 },
  { 123350, 4498.88 },
  { 123800, 4499.87 },
  { 124250, 4500.85 },
  { 124700, 4501.81 },
  { 125151, 4502.75 },
  { 125601, 4503.67 },
  { 126052, 4504.58 },
  { 126502, 4505.47 },
  { 126953, 4506.35 },
  { 127403, 4507.20 },
  { 127854, 4508.04 },
  { 128305, 4508.86 },
  { 128756, 4509.66 },
  { 129207, 4510.44 },
  { 129658, 4511.20 },
  { 130109, 4511.95 },
  { 130561, 4512.67 },
  { 131012, 4513.37 },
  { 131463, 4514.06 },
  { 131915, 4514.72 },
  { 132367, 4515.37 },
  { 132818, 4515.99 },
  { 133270, 4515.45 },
  { 133721, 4512.06 },
  { 134171, 4505.31 },
  { 134621, 4495.18 },
  { 135069, 4481.69 },
  { 135516, 4464.82 },
  { 135960, 4444.57 },
  { 136402, 4420.96 },
  { 136842, 4393.96 },
  { 137278, 4363.59 },
  { 137711, 4329.84 },
  { 138140, 4292.72 },
  { 138565, 4252.22 },
  { 138986, 4208.34 },
  { 139402, 4161.09 },
  { 139813, 4110.46 },
  { 140219, 4056.45 },
  { 140619, 3999.07 },
  { 141013, 3938.32 },
  { 141400, 3874.19 },
  { 141781, 3806.69 },
  { 142154, 3735.81 },
  { 142521, 3661.57 },
  { 142879, 3583.96 },
  { 143229, 3502.98 },
  { 143571, 3418.63 },
  { 143904, 3330.92 },
  { 144228, 3241.00 },
  { 144543, 3150.53 },
  { 144849, 3060.06 },
  { 145146, 2969.58 },
  { 145434, 2879.09 },
  { 145713, 2788.60 },
  { 145983, 2698.10 },
  { 146244, 2607.60 },
  { 146495, 2517.09 },
  { 146738, 2426.58 },
  { 146972, 2336.07 },
  { 147196, 2245.56 },
  { 147412, 2155.04 },
  { 147618, 2064.53 },
  { 147816, 1974.02 },
  { 148004, 1883.51 },
  { 148183, 1793.00 },
  { 148353, 1702.49 },
  { 148515, 1611.98 },
  { 148667, 1521.48 },
  { 148810, 1430.97 },
  { 148944, 1340.47 },
  { 149069, 1249.97 },
  { 149185, 1160.62 },
  { 149292, 1074.10 },
  { 149391, 990.937 },
  { 149483, 911.123 },
  { 149566, 834.662 },
  { 149642, 761.554 },
  { 149711, 691.798 },
  { 149774, 625.394 },
  { 149830, 562.343 },
  { 149880, 502.644 },
  { 149925, 446.297 },
  { 149964, 393.301 },
  { 149999, 343.657 },
  { 150028, 297.365 },
  { 150054, 254.424 },
  { 150075, 214.834 },
  { 150093, 178.596 },
  { 150108, 145.709 },
  { 150119, 116.173 },
  { 150128, 89.9888 },
  { 150135, 67.1552 },
  { 150140, 47.6727 },
  { 150143, 31.5413 },
  { 150145, 18.7609 },
  { 150146, 9.33152 },
  { 150146, 3.25320 },
  { 150146, 0.525893 },
  { 150146, 0.00000 }
};
extern const robovikes::TrajectoryPoint rightTrajectories[] = {
  // { position (R), velocity (RPM) },
  { 0.158261, 3.16522 },
  { 0.185541, 0.272801 },
  { 0.997180, 8.11639 },
  { 3.63847, 26.4129 },
  { 7.76548, 41.2701 },
  { 13.7083, 59.4287 },
  { 21.7972, 80.8886 },
  { 32.3622, 105.650 },
  { 45.7334, 133.712 },
  { 62.2408, 165.075 },
  { 82.2146, 199.738 },
  { 105.985, 237.701 },
  { 133.881, 278.963 },
  { 166.233, 323.525 },
  { 203.372, 371.384 },
  { 245.626, 422.541 },
  { 293.325, 476.994 },
  { 346.800, 534.742 },
  { 406.378, 595.785 },
  { 472.390, 660.120 },
  { 545.165, 727.747 },
  { 625.031, 798.664 },
  { 712.318, 872.868 },
  { 807.354, 950.359 },
  { 910.467, 1031.13 },
  { 1021.99, 1115.19 },
  { 1142.24, 1202.52 },
  { 1271.39, 1291.49 },
  { 1409.43, 1380.42 },
  { 1556.36, 1469.33 },
  { 1712.18, 1558.22 },
  { 1876.89, 1647.07 },
  { 2050.48, 1735.89 },
  { 2232.95, 1824.68 },
  { 2424.29, 1913.43 },
  { 2624.50, 2002.14 },
  { 2833.59, 2090.82 },
  { 3051.53, 2179.46 },
  { 3278.34, 2268.05 },
  { 3514.00, 2356.60 },
  { 3758.51, 2445.10 },
  { 4011.86, 2533.55 },
  { 4274.06, 2621.96 },
  { 4545.09, 2710.31 },
  { 4824.95, 2798.60 },
  { 5113.63, 2886.85 },
  { 5411.14, 2975.03 },
  { 5717.45, 3063.16 },
  { 6032.57, 3151.22 },
  { 6356.50, 3239.22 },
  { 6689.05, 3325.51 },
  { 7029.89, 3408.45 },
  { 7378.69, 3488.04 },
  { 7735.12, 3564.28 },
  { 8098.84, 3637.18 },
  { 8469.51, 3706.73 },
  { 8846.81, 3772.95 },
  { 9230.39, 3835.82 },
  { 9619.93, 3895.36 },
  { 10015.1, 3951.56 },
  { 10415.5, 4004.44 },
  { 10820.9, 4053.99 },
  { 11230.9, 4100.22 },
  { 11645.3, 4143.13 },
  { 12063.5, 4182.72 },
  { 12485.4, 4219.00 },
  { 12910.6, 4251.97 },
  { 13338.8, 4281.64 },
  { 13769.6, 4308.01 },
  { 14202.7, 4331.08 },
  { 14637.8, 4350.86 },
  { 15074.5, 4367.36 },
  { 15512.6, 4380.57 },
  { 15951.6, 4390.50 },
  { 16391.3, 4397.16 },
  { 16831.4, 4400.55 },
  { 17271.5, 4400.68 },
  { 17711.4, 4399.18 },
  { 18151.2, 4397.68 },
  { 18590.8, 4396.17 },
  { 19030.2, 4394.67 },
  { 19469.6, 4393.17 },
  { 19908.7, 4391.66 },
  { 20347.7, 4390.16 },
  { 20786.6, 4388.66 },
  { 21225.3, 4387.16 },
  { 21663.9, 4385.66 },
  { 22102.3, 4384.16 },
  { 22540.6, 4382.66 },
  { 22978.7, 4381.17 },
  { 23416.7, 4379.67 },
  { 23854.5, 4378.18 },
  { 24292.1, 4376.68 },
  { 24729.7, 4375.19 },
  { 25167.0, 4373.70 },
  { 25604.2, 4372.20 },
  { 26041.3, 4370.72 },
  { 26478.2, 4369.23 },
  { 26915.0, 4367.74 },
  { 27351.6, 4366.25 },
  { 27788.1, 4364.77 },
  { 28224.4, 4363.29 },
  { 28660.6, 4361.81 },
  { 29096.7, 4360.33 },
  { 29532.5, 4358.85 },
  { 29968.3, 4357.37 },
  { 30403.9, 4355.90 },
  { 30839.3, 4354.42 },
  { 31274.6, 4352.95 },
  { 31709.8, 4351.48 },
  { 32144.8, 4350.01 },
  { 32579.6, 4348.54 },
  { 33014.3, 4347.08 },
  { 33448.9, 4345.61 },
  { 33883.3, 4344.15 },
  { 34317.6, 4342.69 },
  { 34751.7, 4341.23 },
  { 35185.7, 4339.77 },
  { 35619.5, 4338.31 },
  { 36053.2, 4336.86 },
  { 36486.7, 4335.40 },
  { 36920.1, 4333.95 },
  { 37353.4, 4332.50 },
  { 37786.5, 4331.05 },
  { 38219.4, 4329.61 },
  { 38652.3, 4328.16 },
  { 39084.9, 4326.72 },
  { 39517.4, 4325.27 },
  { 39949.8, 4323.83 },
  { 40382.1, 4322.39 },
  { 40814.2, 4320.95 },
  { 41246.1, 4319.51 },
  { 41677.9, 4318.08 },
  { 42109.6, 4316.64 },
  { 42541.1, 4315.21 },
  { 42972.5, 4313.78 },
  { 43403.7, 4312.34 },
  { 43834.8, 4310.91 },
  { 44265.8, 4309.48 },
  { 44696.6, 4308.06 },
  { 45127.2, 4306.63 },
  { 45557.8, 4305.20 },
  { 45988.1, 4303.78 },
  { 46418.4, 4302.35 },
  { 46848.5, 4300.93 },
  { 47278.4, 4299.51 },
  { 47708.2, 4298.09 },
  { 48137.9, 4296.67 },
  { 48567.4, 4295.24 },
  { 48996.8, 4293.83 },
  { 49426.0, 4292.41 },
  { 49855.1, 4290.99 },
  { 50284.1, 4289.57 },
  { 50712.9, 4288.15 },
  { 51141.6, 4286.74 },
  { 51570.1, 4285.32 },
  { 51998.5, 4283.90 },
  { 52426.7, 4282.49 },
  { 52854.9, 4281.07 },
  { 53282.8, 4279.66 },
  { 53710.6, 4278.24 },
  { 54138.3, 4276.83 },
  { 54565.9, 4275.42 },
  { 54993.3, 4274.00 },
  { 55420.5, 4272.59 },
  { 55847.6, 4271.17 },
  { 56274.6, 4269.76 },
  { 56701.5, 4268.34 },
  { 57128.1, 4266.93 },
  { 57554.7, 4265.51 },
  { 57981.1, 4264.10 },
  { 58407.4, 4262.68 },
  { 58833.5, 4261.27 },
  { 59259.5, 4259.85 },
  { 59685.3, 4258.43 },
  { 60111.0, 4257.02 },
  { 60536.6, 4255.60 },
  { 60962.0, 4254.18 },
  { 61387.3, 4252.76 },
  { 61812.4, 4251.34 },
  { 62237.4, 4249.92 },
  { 62662.3, 4248.50 },
  { 63087.0, 4247.08 },
  { 63511.5, 4245.66 },
  { 63936.0, 4244.24 },
  { 64360.2, 4242.81 },
  { 64784.4, 4241.39 },
  { 65208.4, 4239.96 },
  { 65632.2, 4238.54 },
  { 66055.9, 4237.11 },
  { 66479.5, 4235.68 },
  { 66902.9, 4234.25 },
  { 67326.2, 4232.82 },
  { 67749.4, 4231.39 },
  { 68172.4, 4229.95 },
  { 68595.2, 4228.52 },
  { 69017.9, 4227.08 },
  { 69440.5, 4225.64 },
  { 69862.9, 4224.21 },
  { 70285.2, 4222.77 },
  { 70707.3, 4221.32 },
  { 71129.3, 4219.88 },
  { 71551.1, 4218.44 },
  { 71972.8, 4216.99 },
  { 72394.4, 4215.55 },
  { 72815.8, 4214.10 },
  { 73237.1, 4212.65 },
  { 73658.2, 4211.20 },
  { 74079.2, 4209.74 },
  { 74500.0, 4208.29 },
  { 74920.7, 4206.83 },
  { 75341.2, 4205.37 },
  { 75761.6, 4203.92 },
  { 76181.8, 4202.45 },
  { 76601.9, 4200.99 },
  { 77021.9, 4199.53 },
  { 77441.7, 4198.06 },
  { 77861.4, 4196.60 },
  { 78280.9, 4195.13 },
  { 78700.2, 4193.66 },
  { 79119.5, 4192.19 },
  { 79538.5, 4190.71 },
  { 79957.5, 4189.24 },
  { 80376.2, 4187.76 },
  { 80794.9, 4186.28 },
  { 81213.3, 4184.80 },
  { 81631.7, 4183.32 },
  { 82049.9, 4181.84 },
  { 82467.9, 4180.36 },
  { 82885.8, 4178.87 },
  { 83303.5, 4177.39 },
  { 83721.1, 4175.90 },
  { 84138.6, 4174.41 },
  { 84555.8, 4172.92 },
  { 84973.0, 4171.43 },
  { 85390.0, 4169.93 },
  { 85806.8, 4168.44 },
  { 86223.5, 4166.94 },
  { 86640.1, 4165.45 },
  { 87056.5, 4163.95 },
  { 87472.7, 4162.45 },
  { 87888.8, 4160.95 },
  { 88304.7, 4159.45 },
  { 88720.5, 4157.95 },
  { 89136.2, 4156.45 },
  { 89551.7, 4154.95 },
  { 89967.0, 4153.45 },
  { 90382.2, 4151.95 },
  { 90797.3, 4150.44 },
  { 91212.2, 4148.94 },
  { 91626.9, 4147.44 },
  { 92041.5, 4145.94 },
  { 92455.9, 4144.43 },
  { 92870.2, 4142.93 },
  { 93284.4, 4141.43 },
  { 93698.4, 4139.92 },
  { 94112.2, 4138.42 },
  { 94525.9, 4136.92 },
  { 94939.4, 4135.42 },
  { 95352.8, 4133.92 },
  { 95766.1, 4132.42 },
  { 96179.2, 4130.92 },
  { 96592.1, 4129.43 },
  { 97004.9, 4127.93 },
  { 97417.5, 4126.44 },
  { 97830.0, 4124.94 },
  { 98242.4, 4123.45 },
  { 98654.6, 4121.97 },
  { 99066.6, 4120.48 },
  { 99478.5, 4119.00 },
  { 99890.3, 4117.51 },
  { 100302, 4116.04 },
  { 100713, 4114.56 },
  { 101125, 4113.09 },
  { 101536, 4111.62 },
  { 101947, 4110.15 },
  { 102358, 4108.69 },
  { 102768, 4107.23 },
  { 103179, 4105.77 },
  { 103589, 4104.32 },
  { 104000, 4102.88 },
  { 104410, 4101.43 },
  { 104820, 4100.00 },
  { 105230, 4098.56 },
  { 105639, 4097.14 },
  { 106049, 4095.71 },
  { 106458, 4094.30 },
  { 106868, 4092.89 },
  { 107277, 4091.48 },
  { 107686, 4090.09 },
  { 108095, 4088.70 },
  { 108503, 4087.31 },
  { 108912, 4085.93 },
  { 109321, 4084.56 },
  { 109729, 4083.20 },
  { 110137, 4081.85 },
  { 110545, 4080.50 },
  { 110953, 4079.16 },
  { 111361, 4077.84 },
  { 111768, 4076.52 },
  { 112176, 4075.20 },
  { 112583, 4073.90 },
  { 112991, 4072.61 },
  { 113398, 4071.33 },
  { 113805, 4070.06 },
  { 114212, 4068.80 },
  { 114618, 4067.55 },
  { 115025, 4066.31 },
  { 115432, 4065.08 },
  { 115838, 4063.86 },
  { 116244, 4062.66 },
  { 116650, 4061.47 },
  { 117056, 4060.29 },
  { 117462, 4059.12 },
  { 117868, 4057.97 },
  { 118274, 4056.83 },
  { 118679, 4055.70 },
  { 119085, 4054.59 },
  { 119490, 4053.49 },
  { 119895, 4052.40 },
  { 120300, 4051.33 },
  { 120706, 4050.28 },
  { 121110, 4049.24 },
  { 121515, 4048.22 },
  { 121920, 4047.21 },
  { 122325, 4046.22 },
  { 122729, 4045.24 },
  { 123134, 4044.28 },
  { 123538, 4043.34 },
  { 123942, 4042.41 },
  { 124346, 4041.50 },
  { 124750, 4040.61 },
  { 125154, 4039.74 },
  { 125558, 4038.88 },
  { 125962, 4038.05 },
  { 126366, 4037.23 },
  { 126769, 4036.43 },
  { 127173, 4035.65 },
  { 127576, 4034.88 },
  { 127980, 4034.14 },
  { 128383, 4033.42 },
  { 128786, 4032.71 },
  { 129190, 4032.03 },
  { 129593, 4031.36 },
  { 129996, 4030.72 },
  { 130399, 4030.09 },
  { 130802, 4028.46 },
  { 131204, 4024.34 },
  { 131606, 4017.26 },
  { 132007, 4007.21 },
  { 132406, 3994.21 },
  { 132804, 3978.25 },
  { 133200, 3959.33 },
  { 133594, 3937.46 },
  { 133985, 3912.63 },
  { 134373, 3884.85 },
  { 134759, 3854.11 },
  { 135141, 3820.42 },
  { 135519, 3783.78 },
  { 135894, 3744.19 },
  { 136264, 3701.63 },
  { 136629, 3656.13 },
  { 136990, 3607.67 },
  { 137346, 3556.26 },
  { 137696, 3501.89 },
  { 138040, 3444.56 },
  { 138379, 3384.27 },
  { 138711, 3321.03 },
  { 139036, 3254.82 },
  { 139355, 3185.66 },
  { 139666, 3113.53 },
  { 139970, 3038.43 },
  { 140266, 2960.38 },
  { 140554, 2880.37 },
  { 140834, 2799.91 },
  { 141106, 2719.47 },
  { 141370, 2639.02 },
  { 141626, 2558.59 },
  { 141874, 2478.16 },
  { 142113, 2397.74 },
  { 142345, 2317.32 },
  { 142569, 2236.91 },
  { 142785, 2156.49 },
  { 142992, 2076.08 },
  { 143192, 1995.67 },
  { 143383, 1915.26 },
  { 143567, 1834.86 },
  { 143742, 1754.45 },
  { 143910, 1674.04 },
  { 144069, 1593.62 },
  { 144220, 1513.21 },
  { 144364, 1432.80 },
  { 144499, 1352.38 },
  { 144626, 1271.96 },
  { 144745, 1191.54 },
  { 144856, 1111.12 },
  { 144959, 1031.72 },
  { 145055, 954.824 },
  { 145143, 880.908 },
  { 145224, 809.970 },
  { 145298, 742.009 },
  { 145366, 677.027 },
  { 145427, 615.021 },
  { 145483, 555.995 },
  { 145533, 499.946 },
  { 145578, 446.875 },
  { 145617, 396.784 },
  { 145652, 349.670 },
  { 145683, 305.536 },
  { 145709, 264.381 },
  { 145732, 226.204 },
  { 145751, 191.007 },
  { 145767, 158.788 },
  { 145780, 129.549 },
  { 145790, 103.289 },
  { 145798, 80.0089 },
  { 145804, 59.7077 },
  { 145808, 42.3858 },
  { 145811, 28.0434 },
  { 145813, 16.6803 },
  { 145814, 8.29667 },
  { 145814, 2.89242 },
  { 145814, 0.467573 },
  { 145814, 0.00000 }
};

} // namespace LeftScaleTrajectories
