%Setting up the variables for Newton's Method

Thr = 0.01;
Check = 100;
Iteration = 1;
i = 0;

%Let Mi represent omega
Mi = 20;

%Newton's Method

while(Check > Thr)
    Mn = Mi-(f(Mi))./(fprime(Mi));
    if Iteration > 1
           Check = abs((Mi - Mn)/Mn);
    end
    Iteration = Iteration + 1;
    Mi = Mn;
end

Iteration
Check
Mn


