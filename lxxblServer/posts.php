<?php
/**
 * Created by PhpStorm.
 * User: luxixi
 * Date: 15/8/3
 * Time: 15:41
 */
define("ISA",1);

include "DB.php";

class posts {

    public function index($id) {
        $db = new DB();
        //echo "asdfasdf";
        if (!$id) {
            $this->render("errorView",['error'=>"该文章不存在或已被删除"]);
        }

        $posts = $db->QueryRow("SELECT * FROM `posts` WHERE `id` = {$id}");
        if (!$posts) {
            $this->render("errorView",['error'=>"该文章不存在或已被删除"]);
        }

        $this->render("postView",['posts'=>$posts]);
    }


    private function render($file,$arr = array()) {

        if (is_array($arr)) {
            extract($arr);
        }

        ob_start();
        ob_implicit_flush();
        require($file.'.php');
        echo ob_get_clean();
        exit;
    }
}

$id = isset($_GET['id'])?intval($_GET['id']):0;

$posts = new posts();

$posts->index($id);

?>







