# PID Controller

Author: Szabolcs Sergyan

## Effect of _P_, _I_, _D_ components

### _P_ component

P component is the proportional term. 
We have an error (actually _cte_), and the purpose of the proportional component is to decrease this error proportionally with the measurement of the error.
The aim of this component is to get closer to the desired trajectory, but it will be overshoot and results a pulsing effect around the trajectory.
```
- Kp * cte
```

### _D_ component

D component is the differential term.
It gives a correction which is proportional with the first derivative of the error (_cte_).
The first derivative can be estimated by the difference of the current error and the previous error divided by the time step. Time step is currently considered as 1.
```
- Kd * (cte - prev_cte)
```

### _I_ component

I component is the integral term.
It is useful to use if there is a drift (i.e. caused by wrong setting of the steering).
The integral term is proportional with the sum of all error values.
```
-Ki * sum(cte)
```

## Parameter selection

I chose hyperparameters manually. First I tuned the _Kp_ parameter. I found that if the value is 0.1 pulsing around the desired trajectory was rather small.

Then I tuned the differenctial part, _Kd_. I found that a relatively greater value should be relevant, so finally I selected 1.0.

For the integral part I used 0 as parameter, because theoretically in the simulator there is no drift.

Tuning of the parameters were made with a constant throttle value, which was 0.3. Then I increased throttle significantly. Break (negative throttle) had to be used when the speed and steering angle was too high.

## Video

This video you can find some steps of parameter tuning and the effecto of _P_ and _D_ components can also be seen. [Link](https://youtu.be/rtNSVUatTw8)