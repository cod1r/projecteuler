const std = @import("std");
var gpa = std.heap.GeneralPurposeAllocator(.{}){};
var alloc = gpa.allocator();

pub fn main() !void {
    var max: usize = 28124;
    var num: usize = 12;
    var abund = std.ArrayList(usize).init(alloc);
    defer abund.deinit();
    while (num < max) : (num += 1) {
        var div_sum: usize = 1;
        var div: usize = 2;
        while (div < num) : (div += 1) {
            if (num % div == 0) {
                div_sum += div;
            }
        }
        if (div_sum > num) {
            try abund.append(num);
        }
    }
    var sum_abund = std.AutoHashMap(usize, usize).init(alloc);
    defer sum_abund.deinit();
    var i: usize = 0;
    while (i < abund.items.len) : (i += 1) {
        var j: usize = 0;
        while (j < abund.items.len) : (j += 1) {
            if (!sum_abund.contains(abund.items[i] + abund.items[j]) and abund.items[i] + abund.items[j] < max) {
                try sum_abund.put(abund.items[i] + abund.items[j], 1);
            }
        }
    }
    var total: usize = 28123 * (1 + 28123) / 2;
    var map_iter = sum_abund.keyIterator();
    while (map_iter.next()) |val| {
        total -= val.*;
    }
    const stdout = std.io.getStdOut().writer();
    try stdout.print("{}\n", .{total});
}
