// Import the SwiftIO to use the related board functions.
import SwiftIO
// Import the MadBoard to decide which pin is used for the specific function.
import MadBoard


// Read and print the analog input value every second.
while true {
    update()
    sleep(ms: 10)
}

func update() {
    let analogPin1 = AnalogIn(Id.A1)
    let analogPin2 = AnalogIn(Id.A2)
    let analogPin3 = AnalogIn(Id.A3)

    let analogValue1 = analogPin1.readVoltage()
    let analogValue2 = analogPin2.readVoltage()
    let analogValue3 = analogPin3.readVoltage()
    
    print("Accel (A1): \(floatToString(analogValue1))v; Brake (A2): \(floatToString(analogValue2))v; Angle (A3): \(floatToString(analogValue3))")
}

// Custom function to convert Float to String
func floatToString(_ value: Float, decimalPlaces: Int = 2) -> String {
    let multiplier = powerOfTen(decimalPlaces)
    let intValue = Int(value * multiplier) // Convert float to int
    let integerPart = intValue / Int(multiplier) // Integer part
    var decimalPart = abs(intValue % Int(multiplier)) // Decimal part
    
    // Manually pad the decimal part to the specified number of decimal places
    var decimalPartString = "\(decimalPart)"
    while decimalPartString.count < decimalPlaces {
        decimalPartString = "0" + decimalPartString
    }

    return "\(integerPart).\(decimalPartString)"
}

// Helper function to calculate powers of ten
func powerOfTen(_ exponent: Int) -> Float {
    var result: Float = 1.0
    for _ in 0..<exponent {
        result *= 10
    }
    return result
} 