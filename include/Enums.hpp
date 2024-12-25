#pragma once

namespace FileSorterProgram {
    
    enum class SortType {
        Unknown,
        Year,
        Month
    };

    enum class TransferType {
        Unknown,
        Move,
        Copy
    };

    enum class Months {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };

    enum class ExtensionMatch {
        Unknown,
        PNG,
        JPG,
        Video
    };

}
