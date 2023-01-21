<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>5 Звёзд - Найди свой фильм</title>

    <link href="css/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" href="css/style.css">
    <script src="https://kit.fontawesome.com/1c4b9930f2.js" crossorigin="anonymous"></script>
</head>
<body>

<nav class="navbar navbar-expand-md navbar-dark" style="background: #333336">
    <img src="images/logo.png" alt="" class="logo">
    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbar1" aria-controls="navbar1" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
    </button>

    <div class="collapse navbar-collapse" id="navbar1" style="margin-left: 20px;">
        <ul class="navbar-nav mr-auto">
            <li class="nav-item dropdown">
                <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown2" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Жанры</a>
                <div class="dropdown-menu" aria-labelledby="navbarDropdown1">
                    <a class="dropdown-item" href="#section1">Фантастика</a>
                    <a class="dropdown-item" href="#section2">Комендия</a>
                    <a class="dropdown-item" href="#section3">Экшн</a>
                    <a class="dropdown-item" href="#section4">Ужасы</a>
                    <a class="dropdown-item" href="#section5">Фэнтези</a>
                    <a class="dropdown-item" href="#section6">Боевик</a>
                    <a class="dropdown-item" href="#section7">Мелодрама</a>
                    <a class="dropdown-item" href="#section8">Триллер</a>
                </div>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="data/clients.html">Пользователи</a>
            </li>
        </ul>
        <div class="form">
          <form class="form-inline my-2 my-lg-0">
            <input type="text" placeholder="Search...">
            <button type="submit"></button>
          </form>
        </div>
        <a href="data/lk.html">
          <i class="fas fa-user" style="font-size: 1.4rem;color: white;margin: 0 10px;"></i>
        </a>
    </div>
</nav>
<main>

 <div class="container-fluid p-0">
     <div id="carouselExampleIndicators" class="carousel slide" data-ride="carousel">
         <ol class="carousel-indicators">
             <li class="active" data-target="#carouselExampleIndicators" data-slide-to="0"></li>
             <li data-target="#carouselExampleIndicators" data-slide-to="1"></li>
             <li data-target="#carouselExampleIndicators" data-slide-to="2"></li>
         </ol>
         <div class="carousel-inner">
             <div class="carousel-item active">
                  <h2>Лучшие фильмы недели:</h2>
                  <img src="images/terminator.jpg" alt="" class="d-block w-100">
                  <h3>Терминатор <br /> 31 октября 2019</h3>
             </div>
             <div class="carousel-item">
                 <h2>Лучшие фильмы недели:</h2>
                 <img src="images/malifisenta.jpeg" alt="" class="d-block w-100">
             </div>
             <div class="carousel-item">
                 <h2>Лучшие фильмы недели:</h2>
                 <img src="images/joker.jpg" alt="" class="d-block w-100">
             </div>
         </div>
        
        <a class="carousel-control-prev" href="#carouselExampleIndicators" data-slide="prev">
            <span class="carousel-control-prev-icon"></span>
        </a>
        <a class="carousel-control-next" href="#carouselExampleIndicators" data-slide="next">
            <span class="carousel-control-next-icon"></span>
        </a>

     </div>
 </div>

   

<div class="lists img-custom"> 
  <div id="section1" class="container-fluid">
  <div class="container"> 
    <div class="row justify-content-between">

    <div class="col-4 align-self-start">
      <h1>Фантастика </h1> 
    </div>
    <div class="more"> 
      <a href="data/index_genre_fantastic.html" >Ещё...</a>
    </div>

    </div>
    <div class="row">
      <div class="col">
          <img src="images/avatar.jpg" class="rounded" alt="">
           <p>Описание к фильму #1</p>
      </div>
      <div class="col">
          <img src="images/poster_2.png" class="rounded" alt="">
           <p>Описание к фильму #2</p>
      </div>
      <div class="col">
          <img src="images/poster_3.png" class="rounded" alt="">
           <p>Описание к фильму #3</p>
      </div>
      <div class="col">
          <img src="images/poster_4.png" class="rounded" alt="">
           <p>Описание к фильму #4</p>
      </div>
      <div class="col">
          <img src="images/poster_5.png" class="rounded" alt="">
          <p>Описание к фильму #5</p>
      </div>
    </div>  
  </div>
  
</div>


<div id="section2" class="container-fluid">
  <div class="container">
    <div class="row justify-content-between">

    <div class="col-4 align-self-start">
      <h1>Комедия</h1> 
    </div>
    <div class="more"> 
      <a href="data/index_genre_fantastic.html" >Ещё...</a>
    </div>

    </div>
    <div class="row">
        <div class="col">
          <img src="images/poster_1.png" class="rounded" alt="">
           <p>Описание к фильму #1</p>
        </div>
        <div class="col">
            <img src="images/poster_2.png" class="rounded" alt="">
             <p>Описание к фильму #2</p>
        </div>
        <div class="col">
            <img src="images/poster_3.png" class="rounded" alt="">
             <p>Описание к фильму #3</p>
        </div>
        <div class="col">
            <img src="images/poster_4.png" class="rounded" alt="">
             <p>Описание к фильму #4</p>
        </div>
        <div class="col">
            <img src="images/poster_5.png" class="rounded" alt="">
            <p>Описание к фильму #5</p>
        </div>
    </div>
  </div>
</div>

<div id="section3" class="container-fluid">
  <div class="container">
    <div class="row justify-content-between">

    <div class="col-4 align-self-start">
      <h1>Экшн</h1>
    </div>
    <div class="more"> 
      <a href="data/index_genre_fantastic.html" >Ещё...</a>
    </div>

    </div>
    <div class="row">
        <div class="col">
          <img src="images/poster_1.png" class="rounded" alt="">
           <p>Описание к фильму #1</p>
        </div>
        <div class="col">
            <img src="images/poster_2.png" class="rounded" alt="">
            <p>Описание к фильму #2</p>
        </div>
        <div class="col">
            <img src="images/poster_3.png" class="rounded" alt="">
            <p>Описание к фильму #3</p>
        </div>
        <div class="col">
            <img src="images/poster_4.png" class="rounded" alt="">
            <p>Описание к фильму #4</p>
        </div>
        <div class="col">
            <img src="images/poster_5.png" class="rounded" alt="">
            <p>Описание к фильму #5</p>
        </div>
    </div>
  </div>
</div>
<div id="section4" class="container-fluid">
  <div class="container">
    <div class="row justify-content-between">

    <div class="col-4 align-self-start">
      <h1>Ужасы</h1>
    </div>
    <div class="more"> 
      <a href="data/index_genre_fantastic.html" >Ещё...</a>
    </div>

    </div>
    <div class="row">
        <div class="col">
            <img src="images/poster_1.png" class="rounded" alt="">
            <p>Описание к фильму #1</p>
        </div>
        <div class="col">
            <img src="images/poster_2.png" class="rounded" alt="">
            <p>Описание к фильму #2</p>
        </div>
        <div class="col">
            <img src="images/poster_3.png" class="rounded" alt="">
            <p>Описание к фильму #3</p>
        </div>
        <div class="col">
            <img src="images/poster_4.png" class="rounded" alt="">
            <p>Описание к фильму #4</p>
        </div>
        <div class="col">
            <img src="images/poster_5.png" class="rounded" alt="">
            <p>Описание к фильму #5</p>
        </div>
    </div>
  </div>
</div>

<div id="section5" class="container-fluid">
  <div class="container">
    <div class="row justify-content-between">

    <div class="col-4 align-self-start">
      <h1>Фэнтези</h1>
    </div>
    <div class="more"> 
      <a href="data/index_genre_fantastic.html" >Ещё...</a>
    </div>

    </div>
    <div class="row">
        <div class="col">
            <img src="images/poster_1.png" class="rounded" alt="">
            <p>Описание к фильму #1</p>
        </div>
        <div class="col">
            <img src="images/poster_2.png" class="rounded" alt="">
            <p>Описание к фильму #2</p>
        </div>
        <div class="col">
            <img src="images/poster_3.png" class="rounded" alt="">
            <p>Описание к фильму #3</p>
        </div>
        <div class="col">
            <img src="images/poster_4.png" class="rounded" alt="">
            <p>Описание к фильму #4</p>
        </div>
        <div class="col">
            <img src="images/poster_5.png" class="rounded" alt="">
            <p>Описание к фильму #5</p>
        </div>
    </div>
  </div>
</div>

<div id="section6" class="container-fluid">
  <div class="container">
    <div class="row justify-content-between">

    <div class="col-4 align-self-start">
      <h1>Боевик</h1>
    </div>
    <div class="more"> 
      <a href="data/index_genre_fantastic.html" >Ещё...</a>
    </div>

    </div>
    <div class="row">
        <div class="col">
            <img src="images/poster_1.png" class="rounded" alt="">
            <p>Описание к фильму #1</p>
        </div>
        <div class="col">
            <img src="images/poster_2.png" class="rounded" alt="">
            <p>Описание к фильму #2</p>
        </div>
        <div class="col">
            <img src="images/poster_3.png" class="rounded" alt="">
            <p>Описание к фильму #3</p>
        </div>
        <div class="col">
            <img src="images/poster_4.png" class="rounded" alt="">
            <p>Описание к фильму #4</p>
        </div>
        <div class="col">
            <img src="images/poster_5.png" class="rounded" alt="">
            <p>Описание к фильму #5</p>
        </div>
    </div>
  </div>
</div>

<div id="section7" class="container-fluid">
  <div class="container">
      <div class="row justify-content-between">

        <div class="col-4 align-self-start">
          <h1>Мелодрамма</h1>
        </div>
        <div class="more"> 
          <a href="data/index_genre_fantastic.html" >Ещё...</a>
        </div>

      </div>
    <div class="row">
        <div class="col">
            <img src="images/poster_1.png" class="rounded" alt="">
            <p>Описание к фильму #1</p>
        </div>
        <div class="col">
            <img src="images/poster_2.png" class="rounded" alt="">
            <p>Описание к фильму #2</p>
        </div>
        <div class="col">
            <img src="images/poster_3.png" class="rounded" alt="">
            <p>Описание к фильму #3</p>
        </div>
        <div class="col">
            <img src="images/poster_4.png" class="rounded" alt="">
            <p>Описание к фильму #4</p>
        </div>
        <div class="col">
            <img src="images/poster_5.png" class="rounded" alt="">
            <p>Описание к фильму #5</p>
        </div>
    </div>
  </div>
</div>

<div id="section8" class="container-fluid">
  <div class="container">
    <div class="row justify-content-between">

        <div class="col-4 align-self-start">
        <h1>Триллер</h1>
        </div>
        <div class="more"> 
          <a href="data/index_genre_fantastic.html" >Ещё...</a>
        </div>

    </div>
    <div class="row">
        <div class="col">
            <img src="images/poster_1.png" class="rounded" alt="">
            <p>Описание к фильму #1</p>
        </div>
        <div class="col">
            <img src="images/poster_2.png" class="rounded" alt="">
            <p>Описание к фильму #2</p>
        </div>
        <div class="col">
            <img src="images/poster_3.png" class="rounded" alt="">
            <p>Описание к фильму #3</p>
        </div>
        <div class="col">
            <img src="images/poster_4.png" class="rounded" alt="">
            <p>Описание к фильму #4</p>
        </div>
        <div class="col">
            <img src="images/poster_5.png" class="rounded" alt="">
            <p>Описание к фильму #5</p>
        </div>
    </div>
  </div>
</div>
</div>



</main>
<footer>
  <div class="container-fluid py-4" style="background: #494a4a">
    <div class="container">
      <div class="row">
        <div class="col-6 m-auto">
          <p>
            Lorem ipsum dolor sit amet, consectetur adipisicing elit. Numquam sint eos quibusdam reiciendis quas dolor saepe vitae, dolorum aut ea voluptatum, eligendi accusantium sequi vel nihil quisquam! Nam, rerum, ipsam.
          </p>
        </div>
      </div>
      <div class="row">
        <div class="col">
          <span class="copyright float-right">© 2019 Aleksey Asselborn & Alexander Demin<br> All Rights Reserved</span>
        </div>
      </div>
    </div>
  </div>
</footer>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
    <script src="js/bootstrap.min.js"></script>
</body>
</html>