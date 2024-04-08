# CalendarApp

Developed a C++ calendar application with a Qt GUI interface. 

Functionalities include:
  - adding events
      - ability to create reocurring events with a range of dates of which the events will be reoccurring and on which day of the week
      - includes time, location, and date
  - adding assignments
      - includes due date, and other information
  - calendar View
      - double-click on any given day and it will show you the events for that day
      - click the weekView checkbox and it will show you the schedule of the week (with 30-minute time intervals) of the last clicked on           date on the calendar
  - assignment View
      - you can view you assignment list and you have the ability to remove the assignment when you're done
   
I used qmake and it's mainly for desktop (arm-darwin-generic-mach_o-32bit) usage only right now, but in the future, I can expand to CMake and make it usable across different platforms.
