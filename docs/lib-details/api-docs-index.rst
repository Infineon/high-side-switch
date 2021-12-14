High-Side-Switch Implementation Guide  
------------------------------------------
This section covers the API implementation for High Side Switches used in the Profet family of shields.
This library is currently usable with:

* Profet 12V Shield with BTS7002, BTS7004, BTS7006 or BTS7008 variant
* Profet 12V Shield with BTS50010 or BTS50015 variant 
* Profet 24V Shield with BTT6030 and BTT6020 variant

The implemented APIs, turn the loads ON and OFF by switching the positive (high-) side of the load supply.
Additionaly, it covers sense and diagnostic functionalities to flag any unintended system behavior.
