
%Part 2: Setting up the bisection and regula falsi methods
Thr = 0.01;
Check = 100;
Iteration = 0;

%Initial Interval[1, 1000]
% Let A and B represent omega

A = 1;
B = 1000;

while Check > Thr
    Method = 1;
%Bisection method
    if Method == 1
        Mi = (A + B)/2;

        if f(Mi)*f(A) < 0
            B = Mi;
        else
            A = Mi;
        end
        Iteration = Iteration + 1;
    end
%Regula Falsi Method
    if Method == 0
        (A*f(B) - B*f(A))/(f(B)-f(A));

        if f(Mi)*f(A) < 0
            B = Mi;
        else
            A = Mi;
        end
    end
    

    if Iteration > 1
        Check  = abs((Mn-Mi)/(Mi));
        Iteration = Iteration +1;

        if Method == 0
            Method = 1;
        else
            Method = 0;
        end
    end
     Mn = Mi;
 end

Iteration
Check
Mn



