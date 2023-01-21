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
  height: 1100px;
  padding: 10px; /* Отступ текста от краёв блока */
  background: #ffffff; /* Фон статьи */
  border-radius: 0px;
  box-shadow: rgba(0,0,0,0.5) 0px 1px 3px;
}
.left{ /* Картинка в тексте слева */
  float: left;
  margin: 30px 7px 7px 7px;
}
.right{ /* Картинка в тексте справа */
  float: right;
  margin: 30px 7px 7px 7px;
}

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
<!--Картинка слева-->
      <img class="left" src="https://img.wallpapersafari.com/desktop/1920/1080/24/92/gmxZXE.png"Width="200" Height="200">
<!--Заголовок статьи-->
        <h3>О салоне</h3>
<!--Текст статьи-->
<p>Добро пожаловать на сайт парикмахерской!</p>
<p>Наша парикмахерсая - это место, где руками мастеров пробуждается ваша красота!
Мы стремимся создавать и опережать тенденции  моды в области beauty-индустрии, 
чтобы предоставлять клиентам лучшие решения. Опыт более 10 лет, творческий
подход и профессиональные материалы для ваших современных образов!</p>
<p>Профессионалы всегда на связи! Задать вопрос, проконсультироваться,
записаться на сеанс можно с 8:00 до 20:00 по телефону. Мы ежедневно 
отвечаем на письма, отправленные через контактную форму.Выше в разделе 
"контакты" можно узнать координаты нашаего салона красоты в Волгограде
и посмотреть схему проезда через любое приложение с навигацией.</p>
<!--Картинка справа-->
      <img class="right" src="https://ds02.infourok.ru/uploads/ex/0453/00008d0a-85488700/hello_html_6ff68c3b.png" Width="200" Height="202">
<p>Почему стоит выбрать «Ykladka»
<p>Салон красоты работает на базе Академии красоты 
по методике Pivot Point;
<p>Клиентов салона обслуживают только квалифицированные специалисты с огромным опытом;
<p>Мы используем проверенные и качественные материалы, некоторые из которых представлены у нас в салоне;
<p>Обратившись в наш салон красоты, клиент получает 100% качественные услуги в удобное для него время.</p>
<table>
<input type="text" id="text-to-find" value=""> 
<input type="button" onclick="javascript: FindOnPage('text-to-find'); return false;" value="Искать"/>
<br/><i>Введите слово или фразу для поиска.</i>
<hr/>
 
<table border='2' cellpadding='20'>
 
00:25:8E WeatherC The Weather Channel<br>
00:25:8F TridentM Trident Microsystems, Inc.<br>
00:25:90 SuperMic Super Micro Computer, Inc.<br>
00:25:91 Nextek NEXTEK, Inc.<br>
00:25:92 Guangzho Guangzhou Shirui Electronic Co., Ltd<br>
00:25:93 DatnetIn DatNet Informatikai Kft.<br>
00:25:94 Eurodesi Eurodesign BG LTD<br>
00:25:95 Northwes Northwest Signal Supply, Inc<br>
00:25:96 Gigavisi GIGAVISION srl<br>
00:25:97 KalkiCom Kalki Communication Technologies<br>
00:25:98 ZhongSha Zhong Shan City Litai Electronic Industrial Co. Ltd<br>
00:25:99 HedonEDB Hedon e.d. B.V.<br>
00:25:9A Cestroni CEStronics GmbH<br>
00:25:9B BeijingP Beijing PKUNITY Microsystems Technology Co., Ltd<br>
00:25:9C Cisco-Li Cisco-Linksys, LLC<br>
00:25:9D Private<br>
00:25:9E HuaweiTe Huawei Technologies Co., Ltd.<br>
00:25:9F Technodi TechnoDigital Technologies GmbH<br>
00:25:A0 Nintendo Nintendo Co., Ltd.<br>
00:25:A1 Enalasys<br>
00:25:A2 AltaDefi Alta Definicion LINCEO S.L.<br>
00:25:A3 TrimaxWi Trimax Wireless, Inc.<br>
00:25:A4 Eurodesi EuroDesign embedded technologies GmbH<br>
00:25:A5 WalnutMe Walnut Media Network<br>
00:25:A6 CentralN Central Network Solution Co., Ltd.<br>
00:25:A7 Comverge Comverge, Inc
</table>
    </div>
<!--Запрет наплывания-->
  <div class="clear"></div>
  <script type="text/javascript">
var lastResFind=""; // последний удачный результат
var copy_page=""; // копия страницы в ихсодном виде
function TrimStr(s) {
     s = s.replace( /^\s+/g, '');
  return s.replace( /\s+$/g, '');
}
function FindOnPage(inputId) {//ищет текст на странице, в параметр передается ID поля для ввода
  var obj = window.document.getElementById(inputId);
  var textToFind;
  
  if (obj) {
    textToFind = TrimStr(obj.value);//обрезаем пробелы
  } else {
    alert("Введенная фраза не найдена");
    return;
  }
  if (textToFind == "") {
    alert("Вы ничего не ввели");
    return;
  }
   
  if(document.body.innerHTML.indexOf(textToFind)=="-1")
  alert("Ничего не найдено, проверьте правильность ввода!");
   
  if(copy_page.length>0)
        document.body.innerHTML=copy_page;
  else copy_page=document.body.innerHTML;
 
   
  document.body.innerHTML = document.body.innerHTML.replace(eval("/name="+lastResFind+"/gi")," ");//стираем предыдущие якори для скрола
  document.body.innerHTML = document.body.innerHTML.replace(eval("/"+textToFind+"/gi"),"<a name="+textToFind+" style='background:red'>"+textToFind+"</a>"); //Заменяем найденный текст ссылками с якорем;
  lastResFind=textToFind; // сохраняем фразу для поиска, чтобы в дальнейшем по ней стереть все ссылки
  window.location = '#'+textToFind;//перемещаем скрол к последнему найденному совпадению
 } 
</script>
</body>
</html>