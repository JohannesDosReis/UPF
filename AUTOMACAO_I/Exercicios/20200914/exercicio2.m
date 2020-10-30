while (1)
  tensao = double(readAnalogPin(a, "a0")) * 5 / 1023
  if (tensao < 2.0)
    writeDigitalPin(a, "d10", 1)
    writeDigitalPin(a, "d11", 0)
    writeDigitalPin(a, "d12", 0)
  elseif (tensao < 2.5)
    writeDigitalPin(a, "d10", 0)
    writeDigitalPin(a, "d11", 1)
    writeDigitalPin(a, "d12", 0)
  elseif (tensao < 3.5)
    writeDigitalPin(a, "d10", 0)
    writeDigitalPin(a, "d11", 0)
    writeDigitalPin(a, "d12", 1)
  end
  pause(0.5)
end