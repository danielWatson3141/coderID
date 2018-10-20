#!/usr/bin/php
<?php

class ProblemCase {

    private $n, $l;
    private $in, $out;

    public function __construct(&$input) {
        list($this->n, $this->l) = explode(" ", trim(array_shift($input)));
        $this->in = $this->readValues(explode(" ", trim(array_shift($input))));
        $this->out = $this->readValues(explode(" ", trim(array_shift($input))));
    }

    private function readValues($arr) {
        $result = array();
        foreach($arr as $value) {
            $result []= str_split($value);
        }
        return $result;
    }

    public function solve() {
        $flips = 0;
        $zeros_in = $this->countZeros($this->in);
        $zeros_out = $this->countZeros($this->out);
        $possible_flips = array();
        for ($i = 0; $i < $this->l; $i++) {
            $zin = $zeros_in[$i];
            $zout = $zeros_out[$i];
            if ($zin == $zout) {
                if ($zin + $zout == $this->n) {
                    $possible_flips []= $i;
                }
            } else {
                if ($zin + $zout == $this->n) {
                    $this->flip($i);
                    $flips++;
                } else {
                    return "NOT POSSIBLE";
                }
            }
        }
        while (!$this->isSolution() && count($possible_flips) > 0) {
            $combinations = $this->getCombinations($possible_flips);
            foreach($combinations as $comb) {
                $copy = $this->in;
                $copy_flips = $flips;

                foreach($comb as $index) {
                    $this->flip($index);
                    $flips++;
                }
                if ($this->isSolution()) {
                    return $flips;
                }

                $this->in = $copy;
                $flips = $copy_flips;
            }
        }
        return $this->isSolution() ? $flips : "NOT POSSIBLE";
    }

    private function getCombinations($indexes) {
        if (count($indexes) == 1) {
            return array(
                array(),
                $indexes
            );
        }
        $first = array_shift($indexes);
        $combs = $this->getCombinations($indexes);
        $result = array();
        foreach($combs as $comb) {
            $result []= $comb;
        }
        foreach($combs as $comb) {
            $comb []= $first;
            $result []= $comb;
        }
        return $result;
    }

    private function isSolution() {
        $num_in = $this->toNum($this->in);
        $num_out = $this->toNum($this->out);
        sort($num_in);
        sort($num_out);
        return $num_in == $num_out;
    }

    private function toNum($values) {
        $result = array();
        foreach($values as $value) {
            $val = 0;
            $mult = 1;
            for ($i = 0; $i < $this->l; $i++) {
                if ($value[$i] == '1') {
                    $val += $mult;
                }
                $mult *= 2;
            }
            $result []= $val;
        }
        return $result;
    }

    private function flip($num) {
        for($i = 0; $i < $this->n; $i++) {
            if ($this->in[$i][$num] == '0') {
                $this->in[$i][$num] = '1';
            } else {
                $this->in[$i][$num] = '0';
            }
        }
    }

    private function countZeros($values) {
        $zeros = array();
        for ($i = 0; $i < $this->l; $i++) {
            $zeros[$i] = 0;
        }
        foreach($values as $value) {
            for ($c = 0; $c < $this->l; $c++) {
                if ($value[$c] == '0') {
                    $zeros[$c]++;
                }
            }
        }
        return $zeros;
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
