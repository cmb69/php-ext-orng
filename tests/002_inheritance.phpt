--TEST--
Check inheritance classes.
--SKIPIF--
<?php
if (!extension_loaded('orng')) {
    echo 'skip';
}
?>
--FILE--
<?php
const SEED = 50;

$classes = [
    \ORNG\XorShift128Plus::class,
];

foreach ($classes as $class) {
    $object = new $class(SEED);
    if (! $object instanceof \Orng\RNGInterface) {
        echo "NG, ${class} has not implemented \\ORNG\\RNGInterface.";
        return;
    }
}
echo "OK, inheritance is corrected.";
?>
--EXPECT--
OK, inheritance is corrected.
