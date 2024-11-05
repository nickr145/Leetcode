class Solution {
    func calPoints(_ operations: [String]) -> Int {
        var record = [Int]()

        for operation in operations {
            switch operation {
                case "C":
                record.removeLast()
                case "D":
                record.append(record.last! * 2)
                case "+":
                let count = record.count
                record.append(record[count-1] + record[count-2])
                default:
                record.append(Int(operation)!)
            }
        }

        return record.reduce(0) { $0 + $1 }
    }
}
