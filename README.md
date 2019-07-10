# RAILWAY-BOOKING-APPL
[![CircleCI](https://circleci.com/gh/IITH-SBJoshi/concurrency-5/tree/master.svg?style=svg&circle-token=a08811ff656d962de84f59b1ae677f9ef100fa7f)](https://circleci.com/gh/IITH-SBJoshi/concurrency-5/tree/master)

<h1>BOOK MY JOURNEY</h1>
<p>This projects creates an application which helps the user to<br>
book a ticket for the journey.The main part of the project is to<br>
maintain concurrency when multiple users request for booking the<br>
same seat.</p>
<h2>Getting started:</h2>
<h2>Prerequisites</h2>
<p>You need to have a git environment in your local machine.<br>
Enter these commands</p>
<p>sudo apt install git</p>
<p>You need to have QT work frame to run the project.Download it<br>
from this link:</p>
<p>https://www.qt.io</p>
<p>After install run these commands:</p>
<p>sudo apt-get install libqt4-dev</p>
<p>Make sure you have proper version of it</p>
<h2>Cloning and Developing</h2>
<p>A quick introduction of the minimal setup you need to get a<br>
copy of the project and running.Run the</p>
<p>git init<br>
git clone https://github.com/IITH-SBJoshi/concurrency-5.git<br>
<p>The repository will be downloaded<br>
</p>
<p>Run BookMyJourney.pro using qt.</p>
<h2>Build</h2>
<p>Go to the directory where the project is extreacter and run this<br>
command to build the project.</p>
<p>qmake -project &amp;&amp; qmake &amp;&amp; make</p>
<p>We can run it in qt also after opening the BookMyJourney.pro<br>
A run buttun is present in the left bottom of the window or else<br>
CTRL+R will also run the project</p>
<p>
To run the project we should first establish a connection to server,for that make sure that
the server is running.To run the server in your machine run server.cpp
Run these commands :

g++ server.cpp -pthread -o output<br>
./output 
  



![screenshot from 2019-02-28 21-29-30__01](https://user-images.githubusercontent.com/47008906/53589579-bb5c0480-3bb5-11e9-8fb9-4a8f5bc04d47.png)


<h2>Testing and Features:</h2>
<p>This application is a sample of ticket booking system with core<br>
concept of concurrency when multiple users try to book same ticket<br>
at the same time.When we run the project first dialog requires us toi<br>
enter the account details to Log into the app.If the user doesn’t<br>
have an account he can create it also.</p>

![screenshot from 2019-02-28 21-33-50__01](https://user-images.githubusercontent.com/47008906/53588686-8c449380-3bb3-11e9-8c07-7684e3ed26d7.png)


<p>After log in ,user needs to select the origin and destination of</p>
<p>his/her journey and the date of the journey.Booking is allowed only<br>
upto same date of next month.</p>

![screenshot from 2019-02-28 21-34-07__01](https://user-images.githubusercontent.com/47008906/53589934-a9c72c80-3bb6-11e9-9b98-c59d10e0b0e3.png)


<p>After that he/she needs to select the seats he/she like.A disabled<br>
seats means that it already booked and seats selected will be<br>
displayed in red color.</p>

![screenshot from 2019-02-28 21-34-42__01](https://user-images.githubusercontent.com/47008906/53588746-ada57f80-3bb3-11e9-993b-8d43d99f9621.png)


<p>After that user needs to confirm the terms and conditions and make<br>
payment.A timer will be started and he/she should should make<br>
payment before the timer ends or else the tickets will be lost.After<br>
selecting the confirm booking that seats will be locked and before<br>
the timer ends these seats cannot be booked by anyone.</p>

![screenshot from 2019-02-28 21-34-53__01](https://user-images.githubusercontent.com/47008906/53590026-dbd88e80-3bb6-11e9-973a-d495ec0f0d62.png)


<p>When the server goes off accidentally the data is in the server backed up to into two files<br>
named 1.details.txt -> which stores the details of user and his journey
      2.seats.txt -> which stores the seatmatrices.</p>

<h2>Testing</h2>
<p>File test.cpp runs the test and makes sure that concurrency in the server is working fine.<br>
It creates multiple users who try to book same ticket and ensures that only one user books it.<br>
g++ test.cpp -pthread -o output <br>
./output</p>  

<h2>Coding style tests:</h2>
<p>These tests test where there are mistakes in<br>
coding style in our project.Coding style used in this project is Google coding style.<br>
To run the following test run this command<br>
python cpplint.py &lt;c++filename&gt;</p>
<h2>License:</h2>
<p>This project is licensed under the MIT License - see the<br>
https://github.com/IITH-SBJoshi/concurrency-5/blob/master/LICENSE file for<br>
details.</p>

