# Arduino Soil Moisture Tester

Arduino code for a moisture tester that shows results on a display.

Needed:
- soil moisture sensor
- display lcd (compatible with LiquidCrystal lib)

It take 10 samples, one per second, and display the average of the measures.
Number of samples could be tweaked with macro MAX_COUNT (more samples = more precision, but more time to output a result)
