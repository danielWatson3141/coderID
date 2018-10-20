#!/usr/bin/php
<?php

class PermutationsRecord {

    private static $perms = array();

    public static function register($permutation, $toNotify) {
        $len = count(self::$perms);
        for ($i = 0; $i < $len; $i++) {
            if (self::mustGoBefore($permutation, self::$perms[$i][0])) {
                for ($k = $len; $k > $i; $k--) {
                    self::$perms[$k] = self::$perms[$k - 1];
                    self::$perms[$k][1]->index = $k;
                }
                self::$perms[$i] = array($permutation, $toNotify);
                $toNotify->index = $i;
                return;
            }
        }
        self::$perms[] = array($permutation, $toNotify);
        $toNotify->index = $len;
    }

    private static function mustGoBefore($perm1, $perm2) {
        $len = count($perm1);
        for ($i = 0; $i < $len; $i++) {
            if ($perm1[$i] < $perm2[$i]) {
                return true;
            }
            if ($perm1[$i] > $perm2[$i]) {
                return false;
            }
        }
        return false;
    }

}

class ProblemCase {

    private $n, $perm;
    public $index;

    public function __construct(&$input) {
        $this->n = array_shift($input);
        $this->perm = explode(" ", trim(array_shift($input)));
        PermutationsRecord::register($this->perm, $this);
    }

    public function solve() {
        return $this->index < 60 ? "BAD" : "GOOD";
    }

}

class Problem {

    private $cases;

    public function __construct() {
        $this->cases = array();
    }

    public function addCase($case) {
        $this->cases []= $case;
    }

    public function solve() {
        $numCase = 1;
        foreach ($this->cases as $case) {
            $response = $case->solve();
            echo "Case #${numCase}: $response\n";
            $numCase++;
        }
    }

}

class ProblemReader {

    public static function read($inputLines) {
        $problem = new Problem();
        $numCases = array_shift($inputLines);

        for ($case = 1; $case <= $numCases; $case++) {
            $problem->addCase(new ProblemCase($inputLines));
        }

        return $problem;
    }

}

$problem = ProblemReader::read(file($argv[1]));
$problem->solve();
