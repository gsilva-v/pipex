make re
echo -ne "Test1:" 
echo  " ./pipex infile \"cat\" \"wc -l\" outfile "
./pipex infile "cat" "wc -l" outfile 
echo $? > resulprog
<infile cat | wc -l > outpipe
echo $? > resulpipe
echo -ne "Output check: "
if diff outpipe outfile;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo
echo -ne "Exit check: "
if diff resulprog resulpipe;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo

echo -ne "Test2:" 
echo  " ./pipex infile \"tr a b\" \"tr b c\" outfile "
./pipex infile2 "tr a b" "tr b c" outfile && echo $? > resulprog
<infile2 tr a b | tr b c> outpipe && echo $? > resulpipe
echo -ne "Output check: "
if diff outpipe outfile;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo
echo -ne "Exit check: "
if diff resulprog resulpipe;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo

echo -ne "Test3:" 
echo  " ./pipex infile \"cat\" \"wc -l\" outfile "
./pipex infile "cat" "wc -l" outfile
<infile cat | wc -l> outpipe
echo -ne "Output check: "
if diff outpipe outfile;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo
echo -ne "Exit check: "
if diff resulprog resulpipe;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo

echo -ne "Test4:" 
echo  " ./pipex infile \"cat\" \"grep Now\" outfile "
./pipex infile "cat" "grep Now" outfile
<infile cat | grep Now> outpipe
echo -ne "Output check: "
if diff outpipe outfile;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo
echo -ne "Exit check: "
if diff resulprog resulpipe;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo

echo -ne "Test5:" 
echo  " ./pipex infile \"cat\" \"wc -l\" outfile "
./pipex infile "cat" "wc -l" outfile
<infile cat | wc -l> outpipe
echo -ne "Output check: "
if diff outpipe outfile;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo
echo -ne "Exit check: "
if diff resulprog resulpipe;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo

echo -ne "Test6:" 
echo  " ./pipex infile \"cat\" \"wc -l\" outfile "
./pipex infile "cat" "wc -l" outfile
<infile cat | wc -l> outpipe
echo -ne "Output check: "
if diff outpipe outfile;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo
echo -ne "Exit check: "
if diff resulprog resulpipe;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo

echo -ne "Test7:" 
echo  " ./pipex infile \"cat\" \"wc -l\" outfile "
./pipex infile "cat" "wc -l" outfile
<infile cat | wc -l> outpipe
echo -ne "Output check: "
if diff outpipe outfile;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo
echo -ne "Exit check: "
if diff resulprog resulpipe;
    then printf "\033[32m[OK]\033[0m" ;
else printf "\033[31m[KO]\033[0m";
fi
echo