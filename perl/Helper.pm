#!/usr/bin/perl

package Helper;

sub log_time
{
     my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst)=localtime(time);
     my $nice_timestamp = sprintf ( "%04d-%02d-%02d %02d:%02d:%02d",
                                   $year+1900,$mon+1,$mday,$hour,$min,$sec);
     return $nice_timestamp;
}


sub write_log
{
     #open up a log file
     #my $logfile = "program.log";

     my ($want_timestamp,$string) = @_;
     #open LOGFILE, ">>$logfile" or die "cannot create log file! $! \n";
     if ($want_timestamp == 1)
     {
          print log_time(),"\t",$string,"\n";
          #print LOGFILE log_time(),"\t",$string,"\n";
     }
     else
     {
          print $string,"\n";
          #print LOGFILE $string,"\n";
     }
     #close LOGFILE;
}



1;