add_library(neuron SHARED neuron.c)
add_library(neural_network SHARED neural_network.c neuron)
add_executable(neural main.c)
target_link_libraries(neural neural_network)
