//
// Created by joaob on 15/04/2025.
//

#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace prog {
    /**
     * Ensures the folder with the given name exists.
     *
     * @param string the name of the folder
     * @return true if the folder with the name already existed, or could be created, false otherwise
     */
    bool mkdir(const std::string &string);

    /**
     * Deletes all regular files inside the current folder (does not delete files recursively).
     *
     * @param string name of the folder with the files to delete
     * @return true if files could be successfully deleted, false otherwise
     */
    bool delete_files(const std::string &string);
}

#endif //UTILS_H
