<?php session_start(); ?>
<!DOCTYPE html>
<html lang="ru">
<head>
<meta charset="utf-8" />
<title>Код блочного сайта</title>


<style>
body{
  background:#FFC0CB; /* Меняется фон экрана, выбирается здесь */
}

#wrapper{ /* Оболочка страницы сайта */
  width: 900px; /* Меняется ширина страницы */
  margin: 0 auto;
  background:#FFC0CB; /* Меняется задний фон страницы */
}

/* Шапка сайта */

#header{
position:relative; /* Задаём блоку относительное позиционирование для того, чтобы затем размещать, в нём другие элементы и позиционировать относительно его границ поверх фоновой картинки и заголовка */
  height: 400px; /* Высота шапки */
  background-color: #ffffff; /* Фон шапки */
   margin-bottom: 5px; /* Нижний отступ шапки от остального контента */
  border-radius: 5px; /* Закругляются углы блока */
  box-shadow: rgba(0,0,0,0.5) 0px 1px 3px; /* Тень. Визуально приподнимает блок над оболочкой */
}
img{ /* Фоновая картинка в шапке */
float: left; /* Разрешаем наплывание других элементов на картинку */
  margin: -48px 0 0 ;} /* Размещаем картинку в блоке header. 1-я и 3-я цифры - двигаем вверх-вниз, 2-я и 4-я цифры - двигаем вправо-влево */
h1{ /* Заголовок сайта */
  margin:0 0 10px 40px; /* Заголовок двигается верх-вправо-вниз-влево. */
  color:#464451; /* Цвет заголовка */
}
.inform{ /*Подзаголовок (контактная информация )*/
  position:absolute; /* Позиционируем абсолютно подзаголовок, относительно границ блока header. Также можно разместить в шапке сайта ещё другие картинки и абзацы поверх фоновой картинки и заголовка */
  top:10px; /* Двигается вверх-вниз */
  left:600px; /* Двигается вправо-влево */
  font-size: 20px; /* Размер букв подзаголовка */
  font-style:italic; /* Курсив */
  font-weight:bold; /* Жирный */
  color:#464451; /* Цвет букв подзаголовка */
}
#top-menu {width:250px; height:70px; }
.bg-1 {width:890px; height:64px; background:#DB7093 url(images/m1.png) repeat-x; padding:0 0 0 10px;}
.bg-1 ul {margin:0; padding:0; list-style:none;}
.bg-1 ul li {float:left; background:url(images/m2.png) no-repeat right center; padding:0 2px 0 0;}
.bg-1 ul li a {display:block; height:40px; padding:24px 27px 0 27px; color:#000000; text-decoration:none; text-transform:uppercase;}
.bg-1 ul li a:hover {color:#fff; background:#FFC0CB;}

/* Контент (статья) */

#content{ /* Блок контента */
  margin: auto;
  width: 880px; /* Ширина статьи */
  height: 500px;
  padding: 10px; /* Отступ текста от краёв блока */
  background: #ffffff; /* Фон статьи */
  border-radius: 0px;
  box-shadow: rgba(0,0,0,0.5) 0px 1px 3px;
}
table
	{background: #FFFFF0;
	width: 870px;
    height: 70px;}

</style>
</head>
<body>
  <div id="wrapper"> <!--Оболочка страницы-->
<!--Шапка сайта-->
    <div id="header">
<!--Заголовок сайта-->
      <h1>Парикмахерская Ykladka</h1>
<!--Описание (контактная ифнормация)-->
		<p class="inform">Контактная информация <br> Номер телефона:23-28-10
		<br>Адрес: г.Волгоград, ул.Свободы, БЦ "Меркурий", 1 этаж</p>
		
<!--Фоновая картинка в шапке сайта-->
      <img src="https://www.hairfinder.com/hairquestions/hair-care2th.jpg"Width="900" Height="402">
    </div>
<!--Сайдбар-->
 <div id="menu-top">
        <div class="bg-1">
		  <ul>
			<font>
            <li><a href="index.php">Главная</a></li>
			</font>
			<font>
            <li><a href="index_2.php">Услуги</a></li>
			</font>
			<font>
            <li><a href="index_3.php">Акции</a></li>
			<li><a href="index_4.php">Личный кабинет</a><li>
			</font>
            </ul>
			
        </div>
        <div class="bg-2"></div>
    </div>
    </div>
<!--Основной контент (статья)-->
    <div id="content">
<!--Таблица-->
	<table border="1">
	<tr>
	<th>Наименование услуги</th><th>Цены</th>
	</tr>
	<tr>
	<td>Женская стрижка на короткие волосы</td><td> 300р.</td>
	</tr>
	<tr>
	<td>Стрижка на средние волосы</td><td>350-400р.</td>
	</tr>
	<tr>
	<td>Стрижка на длинные волосы</td><td>400-450р.</td>
	</tr>
	<tr>
	<td>Укладка феном</td><td>300р.</td>
	</tr>
	<tr>
	<td>Вечерняя укладка</td><td>500р.</td>
	</tr>
	<tr>
	<td>Шлифовка волос</td><td>400р.</td>
	</tr>
	<tr>
	<td>Окрашивание в один тон</td><td>600р.</td>
	</tr>
	<tr>
	<td>Мелирование+тонирование</td><td>1500р.</td>
	</tr>
	<tr>
	<td>Локоны</td><td>800р.</td>
	</tr>
	<tr>
	<td>Химическая завивка</td><td>800р.</td>
	</tr>
	<tr>
	<td>Долговременная укладка</td><td>700р.</td>
	</tr>
	<tr>
	<td>Подравнивание концов без утюжков</td><td>200р.</td>
	</tr>
	<tr>
	<td>Челка</td><td>100р.</td>
	</tr>
	<tr>
	<td>Сложное окрашивание</td><td>2000р.</td>
	</tr>
	<tr>
	<td>Мужская модельная стрижка</td><td>250р.</td>
	</tr>
	<tr>
	<td>Мужская креативная стрижка</td><td>350р.</td>
	</tr>
	<tr>
	<td>Усы, борода</td><td>150р.</td>
	</tr>
	</table>
	</body>
	</html>