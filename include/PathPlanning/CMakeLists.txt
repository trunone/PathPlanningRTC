set(hdrs PathPlanning.h
    PARENT_SCOPE
    PathServiceSVC_impl.h
    )

install(FILES ${hdrs} DESTINATION ${INC_INSTALL_DIR}/${PROJECT_NAME_LOWER}
    COMPONENT library)

