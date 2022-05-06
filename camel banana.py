total=3000
distance=1000
load_capacity=1000
lose=0
start=total
for i in range(distance):
    while start>0:
        start=start-load_capacity
#Here if condition is checking that camel doesn't move back if there is only one banana left.
        if start==1:
            lose=lose-1#Lose is decreased because if camel try to get remaining one banana he will lose one extra banana for covering that two miles.
#Here we are increasing lose because for moving backward and forward by one mile two bananas will be lose
        lose=lose+2
#Here lose is decreased as in last trip camel will not go back.
    lose=lose-1
    start=total-lose
    if start==0:#Condition to check whether it is possible to take a single banana or not.
        break
print(start)
#print(lose)
