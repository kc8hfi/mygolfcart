package Accelerometer;

use Moose;

has 'x_value' =>
(
     is => 'rw',
     isa => 'Num',
);

has 'y_value' =>
(
     is   =>   'rw',
     isa  =>   'Num',
);

has 'z_value' =>
(
     is   =>   'rw',
     isa  =>   'Num',
);


1;