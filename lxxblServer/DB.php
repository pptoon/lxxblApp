<?php
/**
 * Created by PhpStorm.
 * User: luxixi
 * Date: 15/8/3
 * Time: 15:41
 */
if ( ! defined('ISA')) exit('No direct script access allowed');

class DB {
    private $db;
    const DNS = 'mysql:host=localhost;dbname=ghost';
    const USERNAME = 'you username';
    const PASSWORD = 'you password';
    public function __construct() {
        try {
            $this->db = new \PDO(self::DNS,self::USERNAME,self::PASSWORD,array(\PDO::ATTR_PERSISTENT=>true));
        } catch(\PDOException $e) {

        }
        $this->db->setAttribute(\PDO::ATTR_ERRMODE,\PDO::ERRMODE_EXCEPTION);
        //$this->db->query('SET NAMES utf8');
    }

    public function Query($sql) {
        $std = $this->db->prepare($sql);
        $std->execute();
        $std->setFetchMode(\PDO::FETCH_OBJ);
        return $std->fetchAll();
    }

    public function QueryRow($sql) {
        $std = $this->db->prepare($sql);
        $std->execute();
        $std->setFetchMode(\PDO::FETCH_OBJ);
        return $std->fetch();
    }

}