while (1)
  disp("")
  val = readAnalogPin(a, "a0")
  fprintf("Teclas:")
  if (
    val == 512 ||
    val == 455 ||
    val == 439 ||
    val == 396 ||
    val == 410 ||
    val == 372 ||
    val == 361 ||
    val == 332)
    fprintf(" K1")
  end

  if (
    val == 682 ||
    val == 585 ||
    val == 558 ||
    val == 491 ||
    val == 410 ||
    val == 372 ||
    val == 361 ||
    val == 332)
    fprintf(" K2")

  end
  
  if (
    val == 768 ||
    val == 647 ||
    val == 558 ||
    val == 491 ||
    val == 439 ||
    val == 396 ||
    val == 361 ||
    val == 332)
    fprintf(" K3")

  end
  
  if (
    val == 819 ||
    val == 647 ||
    val == 585 ||
    val == 491 ||
    val == 455 ||
    val == 396 ||
    val == 372 ||
    val == 332)
    fprintf(" K4")
  end

  pause(0.5)
end