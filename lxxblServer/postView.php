
<!DOCTYPE html>
<html>
<head>

    <meta charset="utf-8" />
    <link rel="stylesheet" type="text/css" href="http://ricostacruz.com/nprogress/nprogress.css" />
    <script src="http://code.jquery.com/jquery-1.11.3.js" language="JavaScript"></script>
    <script src="http://ricostacruz.com/nprogress/nprogress.js" language="JavaScript"></script>
    <script>
        NProgress.set(0.5);
        NProgress.start();

        //NProgress.done();
    </script>
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="baidu-site-verification" content="fcJ6bnmM8u" />
    <meta name="google-site-verification" content="nRqxhuveHbFC1NFHdLlkXtHvEBm24FINeiHLUnAzV-I" />
    <title><?php echo $posts->title;?></title>

    <meta name="HandheldFriendly" content="True">
    <meta name="MobileOptimized" content="320">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black-translucent">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <meta name="msapplication-TileColor" content="#00a300">
    <meta name="msapplication-TileImage" content="http://www.lxxbl.com/assets/img/mstile-144x144.png">
    <meta name="msapplication-config" content="http://www.lxxbl.com/assets/img/browserconfig.xml">

    <link rel="stylesheet" type="text/css" href="http://www.lxxbl.com/assets/css/uno.css?v=95417ab4f9" />

    <link rel="canonical" href="http://www.lxxbl.com/php7kuo-zhan-zi-dong-jia-zai-lei/" />

    <meta property="og:site_name" content="卢喜羲博客" />
    <meta property="og:type" content="article" />
    <meta property="og:title" content="<?php echo $posts->title;?>" />
    <meta property="og:description" content="<?php echo $posts->title;?>" />
    <meta property="og:url" content="http://www.lxxbl.com/php7kuo-zhan-zi-dong-jia-zai-lei/" />
    <meta property="article:published_time" content="2015-07-05T16:06:27.000Z" />
    <meta property="article:modified_time" content="2015-08-01T17:52:55.000Z" />
    <meta name="generator" content="Ghost 0.6" />
    <link rel="alternate" type="application/rss+xml" title="卢喜羲博客" href="http://www.lxxbl.com/rss/" />

</head>
<body class="post-template">


<article class="main">
    <section id="search-results"></section>
    <section class="content">


        <article class="post">
            <header>
                <a id="back-button" class="btn small square" href="javascript:history.back()">« Back</a>
                <div class="post meta">
                    <time datetime="06 Jul 2015"><?php echo date('Y m d',strtotime($posts->published_at))?></time>
                    <span class="post tags"></span>
                    <span class="post reading-time"> – <span></span> read.</span>
                </div>

                <a id="share_twitter" alt="Tweet '<?php echo $posts->title;?>'" style="color: #24bfcf" target="_blank">

                    <h1 class="icon-reverse" style="color: #24bfcf" id="post-title"><?php echo $posts->title;?>.</h1>
                </a>
            </header>

            <section class="post">
                <?php echo $posts->html;?>
            </section>

        </article>

  <span class="copyright">
    &copy; 2015. All rights reserved. <a href="https://github.com/lxy254069025" target="_blank">github</a>
  </span>
        </footer>
    </section>
</article>

</body>
</html>
