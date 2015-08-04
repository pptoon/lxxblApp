<?php
/**
 * Created by PhpStorm.
 * User: luxixi
 * Date: 15/8/3
 * Time: 15:41
 */
define("ISA",1);
include "DB.php";

$db = new DB();

$pstsCount = $db->QueryRow("SELECT COUNT(*) AS num FROM posts")->num;


$page = isset($_GET['page'])?$_GET['page']:0;
$page = intval($page);
$size = 4;
$count = $pstsCount;
$count_num = ceil($count/$size);
$start_num = ($page <= 1 ?1:$page)-1;
$start_num = (($start_num * $size)) > 0?(($start_num * $size)):0;

$data = $db->Query("SELECT * FROM `posts` WHERE `status` = 'published' ORDER BY `id` DESC LIMIT {$start_num}, {$size}");

$json = [];
if ($data == null || empty($data)) {
    $json['status'] = 404;
} else {
    $json['status'] = 200;
}


foreach ($data as $k=>$v) {
    $json['msg'][$k]['title'] = $v->title;
    $json['msg'][$k]['desc'] = strip_tags($v->html);
    $json['msg'][$k]['addtime'] = date('Y m d',strtotime($v->published_at));
    $json['msg'][$k]['url'] = "http://weichat.lxxbl.com/posts.php?id=".$v->id;
}
//var_dump($json);exit;
exit(json_encode($json));