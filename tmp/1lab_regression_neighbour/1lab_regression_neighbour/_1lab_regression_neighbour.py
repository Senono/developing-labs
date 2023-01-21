
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import sklearn.neighbors
import sklearn.linear_model


class neighbors:
    def __init__(self, num_neighbors):
        self.n_neighbors = num_neighbors

    def fit(self, x, y):
        self.x = x
        self.y = y

    def predict(self, x_new):
        if type(x_new) == int:
            x_new = np.array([[x_new]])
        elif type(x_new) == list:
            x_new = np.array(x_new)

        return_array = np.zeros((x_new.size, 1))
        for new_x_counter, new_x_value in enumerate(x_new):
            new_x_value = new_x_value[0]
            for counter, value in enumerate(self.x):
                if value[0] > new_x_value:
                    break
            l = []
            for i in range(self.n_neighbors):
                right = counter + i
                left = counter - i - 1
                if right < self.x.size:
                    l.append([abs(new_x_value - self.x[right][0]), right])
                if left >= 0:
                    l.append([abs(new_x_value - self.x[left][0]), left])
            l.sort()
            sum = 0
            for i in range(self.n_neighbors):
                sum += self.y[l[i][1]][0]
            return_array[new_x_counter][0] = sum / self.n_neighbors
        return return_array


def estimate_coef(x, y):
    # количество наблюдений / баллов
    n = np.size(x)
    # среднее значение вектора x и y
    m_x, m_y = np.mean(x), np.mean(y)
    # вычисление перекрестного отклонения и отклонения о х
    SS_xy = np.sum(y * x) - n * m_y * m_x
    SS_xx = np.sum(x * x) - n * m_x * m_x
    # вычисление коэффициентов регрессии
    b_1 = SS_xy / SS_xx
    b_0 = m_y - b_1 * m_x
    return (b_0, b_1)


# =================================================================================================

def plot_regression_line(x, y, b):
    # построение фактических точек в виде точечной диаграммы
    plt.scatter(x, y, color="k", marker="o", s=30)
    # предсказанный вектор ответа
    y_pred = b[0] + b[1] * x
    # построение линии регрессии
    plt.plot(x, y_pred, color="g")
    # нанесение ярлыков
    plt.xlabel('')
    plt.ylabel('Уровень жизни')
    plt.axis([5000, 60000, 4, 8])
    # функция показа сюжета
    plt.show()


def prepare_country_stats(oecd_bli, gdp_per_capita):
    oecd_bli = oecd_bli[oecd_bli["INEQUALITY"] == "TOT"]
    oecd_bli = oecd_bli.pivot(index="Country", columns="Indicator", values="Value")
    gdp_per_capita.rename(columns={"2015": "GDP per capita"}, inplace=True)
    gdp_per_capita.set_index("Country", inplace=True)
    full_country_stats = pd.merge(left=oecd_bli, right=gdp_per_capita,
                                  left_index=True, right_index=True)
    full_country_stats.sort_values(by="GDP per capita", inplace=True)
    remove_indices = [0, 1, 6, 8, 33, 34, 35]
    keep_indices = list(set(range(36)) - set(remove_indices))
    return full_country_stats[["GDP per capita", 'Life satisfaction']].iloc[keep_indices]


# Загрузить данные
XNew = 22587
X_new = [[22587]]
oecd_bli = pd.read_csv("oecd_bli_2015.csv", thousands=',')
gdp_per_capita = pd.read_csv("gdp_per_capita.csv", thousands=',', delimiter='\t',
                             encoding='latin1', na_values="n/a")

# Подготовить данные
country_stats = prepare_country_stats(oecd_bli, gdp_per_capita)
X = np.c_[country_stats["GDP per capita"]]
y = np.c_[country_stats["Life satisfaction"]]
country_stats.plot(kind='scatter', x="GDP per capita", y='Life satisfaction')

# линейная модель sklearn
model = sklearn.linear_model.LinearRegression()
model.fit(X, y)

# своя линейная модель
b = estimate_coef(X, y)
print("Estimated coefficients:\nb_0 = {}\nb_1 = {}".format(b[0], b[1]))

# метод ближайших соседей sklearn
model2 = sklearn.neighbors.KNeighborsRegressor(n_neighbors=1)
model2.fit(X, y)

# свой метод ближайших соседей
model3 = neighbors(3)
model3.fit(X, y)

print("Для ВВП = {}\nУровень жизни:\nМетод линейной регрессии = {}".format(XNew, b[0] + b[1] * XNew))
print("Метод линейной регрессии sklearn = {}".format(model.predict(X_new)[0][0]))
print("Метод ближайших соседей sklearn = " + str(model2.predict(X_new)))
print("Метод ближайших соседей свой = " + str(model3.predict(X_new)))

X_test = np.arange(X[0][0], X[-1][0], 10)
X_test = X_test.reshape((X_test.shape[0], 1))

plot_regression_line(X, y, b)
plt.scatter(X, y, color="black", marker="o", s=40)
plt.plot(X_test, model.predict(X_test), color="blue", linewidth=2)
plt.plot(X_test, model2.predict(X_test), color="green", linewidth=4)
plt.plot(X_test, model3.predict(X_test), color="red", linewidth=2)
plt.xlabel('')
plt.ylabel('Уровень жизни')
plt.axis([5000, 60000, 4, 8])
plt.show()
