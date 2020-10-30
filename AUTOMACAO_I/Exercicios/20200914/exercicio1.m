while (1)
  duty = double(readAnalogPin(a, "a0")) / 1023
  writePWMDutyCycle(a, "d3", duty)
  pause(0.5)
end