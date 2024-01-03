# TFT Backup

```c

  tft.init();

  tft.fillScreen(TFT_BLACK);

  yield();
  Serial.println(F("Benchmark                Time (microseconds)"));

  yield();
  Serial.print(F("Screen fill              "));
  yield();
  Serial.println(testFillScreen());
  // total+=testFillScreen();
  delay(500);

  yield();
  Serial.print(F("Text                     "));
  yield();
  Serial.println(testText());
  // total+=testText();
  // delay(3000);

  yield();
  Serial.print(F("Lines                    "));
  yield();
  Serial.println(testLines(TFT_CYAN));
  // total+=testLines(TFT_CYAN);
  delay(500);

  yield();
  Serial.print(F("Horiz/Vert Lines         "));
  yield();
  Serial.println(testFastLines(TFT_RED, TFT_BLUE));
  // total+=testFastLines(TFT_RED, TFT_BLUE);
  delay(500);

  yield();
  Serial.print(F("Rectangles (outline)     "));
  yield();
  Serial.println(testRects(TFT_GREEN));
  // total+=testRects(TFT_GREEN);
  delay(500);

  yield();
  Serial.print(F("Rectangles (filled)      "));
  yield();
  Serial.println(testFilledRects(TFT_YELLOW, TFT_MAGENTA));
  // total+=testFilledRects(TFT_YELLOW, TFT_MAGENTA);
  delay(500);

  yield();
  Serial.print(F("Circles (filled)         "));
  yield();
  Serial.println(testFilledCircles(10, TFT_MAGENTA));
  // total+= testFilledCircles(10, TFT_MAGENTA);

  yield();
  Serial.print(F("Circles (outline)        "));
  yield();
  Serial.println(testCircles(10, TFT_WHITE));
  // total+=testCircles(10, TFT_WHITE);
  delay(500);

  yield();
  Serial.print(F("Triangles (outline)      "));
  yield();
  Serial.println(testTriangles());
  // total+=testTriangles();
  delay(500);

  yield();
  Serial.print(F("Triangles (filled)       "));
  yield();
  Serial.println(testFilledTriangles());
  // total += testFilledTriangles();
  delay(500);

  yield();
  Serial.print(F("Rounded rects (outline)  "));
  yield();
  Serial.println(testRoundRects());
  // total+=testRoundRects();
  delay(500);

  yield();
  Serial.print(F("Rounded rects (filled)   "));
  yield();
  Serial.println(testFilledRoundRects());
  // total+=testFilledRoundRects();
  delay(500);

  yield();
  Serial.println(F("Done!"));
  yield();
  // Serial.print(F("Total = ")); Serial.println(total);

  // yield();Serial.println(millis()-tn);


  loop{
      for (uint8_t rotation = 0; rotation < 4; rotation++)
  {
    tft.setRotation(rotation);
    testText();
    delay(5000);
  }
  }
```