# Trujillo_Fayez_CSCI2270_FinalProject
Project Summary:
Josh Trujillo and Ahmed Fayez worked on this project together. Our project was a vacation/trip using doubly linked lists. What we did was design a preset vacation that would visit 10 cities, where each city would be a node in our linked list. How it works is upon start up, it will ask you for your name and then begin with a little welcome statement. Then a menu will pop-up showing all the possible options to choose from. "Plan Trip" will build the linked list as well as print out all the linked list cities. "Cancel trip" will completely cancel the entire trip and delete the linked list + free up data/memory and ends the program. "Print Trip" will print out the trip path and all the cities. "Set Budget" will ask the user to set a starting budget for the trip (between and including 100 and 300 dollars). "Start Trip" will begin the trip and print out the first city to be visited. It is important to note that after we "start trip" then from then on a menu will be displayed right below the main menu that will display the current city name, souvenir, price, a hot-spot in that city, as well as your current budget. This menu will continuously show through the rest of the trip so each time you move cities it will display all that information for that particular city. "Travel to next city" just travels you along the linked list to the next city. "Travel to previous city" will allow you to backtrack to the previous city in case the person forgot their purse or wallet at the last stop in their vacation. "Add city" allows you to add a new city to visit along your trip so you can potentially customize this vacation instead of just using our predetermined cities. This option will prompt you for: city name, previous city, souvenir of the new city (optional if not wanted input "NULL), a price for the souvenir, and a local hot-spot for that city (also optional). "Delete City" will allow you to delete a city on your trip, prompting for the city name to be deleted. "Buy souvenir" will buy the current souvenir in the current city that you are at. This will purchase one souvenir at a time and will deduct the amount from your running budget that was initially allocated. "End trip and return home" will end the trip, print out a few messages as well as information about your trip such as your budget and souvenirs that you purchased along your way and ends the program.

How to Run:
For this project all you need are the FinalProject.cpp, Travel.cpp and Travel.h files. Make sure all files are in the same folder and simply through command line type "g++ FinalProject.cpp, Travel.cpp", (aka compile them together), and then run the a.out created and that will begin our program and our welcome messages and prompting for your name will commence.

Dipendencies:
Our program does not have dependencies. All that we have are the included libraries that we included at the top of each file. Pretty standard ones that we have been working with all year. Should not need anything else or any downloadable libraries.

System Requirements:
Our program is entirely written in c++ and is compatible with all operating systems.

Group members:
Josh Trujillo and Ahmed Fayez

Contributors:
Notes provided on moodle by Rhonda Hoenigman were used as references and what not.

Open issues/bugs:
To our knowledge there do not appear to be any bugs but we do welcome greater testing to flesh out any possible bugs that we did not catch.
