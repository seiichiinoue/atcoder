Deg, Dis = map(int, input().split(" "))

Deg = Deg / 10

compass = ['NNE', 'NE', 'ENE', 'E', 'ESE', 'SE', 'SSE', 'S', 'SSW', 'SW', 'WSW', 'W', 'WNW', 'NW', 'NNW']

if Deg - 11.25 < 0 or Deg - 11.25 >= 348.75:
	Deg = 'N'
else:
	Deg = compass[int((Deg - 11.25) // 22.5 % 16)]

Dis = round(float(float(Dis)/60), 1)

dis_table = [0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6, 200.0]

for i in range(13):
    if Dis <= dis_table[i]
        Dis = i
        break

if Dis == 0:
	print('C', 0)
else:
	print(Deg, Dis)