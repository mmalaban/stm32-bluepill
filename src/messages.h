#ifndef MESSAGES_H
#define MESSAGES_H

/**
 * Initialize the CAN bus interface at 500 kbps.
 *
 * @return 0 on success, negative errno on failure.
 */
int messages_init(void);

#endif /* MESSAGES_H */
